from selenium import webdriver
from bs4 import BeautifulSoup
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import re
import pandas as pd
import time

wd = webdriver.Chrome('./WebDriver/chromedriver.exe')

cinemas = ['http://www.cgv.co.kr/movies', 'https://www.lottecinema.co.kr/NLCHS/Movie/List?flag=1', 'https://megabox.co.kr/movie'] # 영화회사 리스트
         # 27 27 27
         #예매율, 에그, 개봉일  #예매율, 별점 #예매율, 개봉일, 좋아요수
result = [[], [], []]
reviews = [[], [], []]
for cinema in cinemas:  # 각 회사 반복
    url = cinema
    print(url)
    wd.get(url)
    wait = WebDriverWait(wd, 10)
    html = wd.page_source
    soup = BeautifulSoup(html, 'html.parser')

    # 현재 상영중인 영화 개수 18개 뽑아냄 이유는 CGV가 19개까지밖에없음
    # CGV는 평점데이터가 없음-_-
    # 골든 에그는 기대-실관람 후기 0~100점인데 대부분 영화가 95점 이상이라 유의미한 가치를 지니지 않음
    movie_elements = soup.select('div.box-image > a')[:18]
    midx_values = [element.get('href').split('=')[-1] for element in movie_elements]
    print(f"From {url}, got {len(midx_values)} midx values.")
    print(midx_values)
    # 각 영화의 상세 페이지로 이동
    for midx in midx_values:
        detail_url = url + '/detail-view/?midx=' + midx
        wd.get(detail_url)

        # 페이지 로딩 완료 대기
        wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.box-contents')))
        time.sleep(2)
        detail_html = wd.page_source
        detail_soup = BeautifulSoup(detail_html, 'html.parser')

        detail_data = {}
        review_data = {}
        try:  # 예외 처리 시작
            # 상세 정보 가져오기
            box_contents = detail_soup.select_one('div.box-contents')
            # 영화 제목, 전체 예매율, 장르
            detail_data['title'] = box_contents.select_one('div.title > strong').text.strip()
            detail_data['reservation_rate'] = box_contents.select_one('div.score > strong > span').text.strip()

            # 성별 예매 분포
            sex_distribution = detail_soup.select_one('div#jqplot_sex')
            gender_distribution = detail_soup.select('div#jqplot_sex span.jqplot-donut-series.jqplot-data-label')
            detail_data['gender_distribution'] = {gender.text.split()[0]: gender.text.split()[1] for gender in
                                                  gender_distribution}

            # 연령별 예매 분포
            age_distribution = detail_soup.select('div#jqplot_age div.jqplot-point-label.jqplot-series-0')
            detail_data['age_distribution'] = {f"{10 * i+10}대": age.text for i, age in enumerate(reversed(age_distribution))}
            print(detail_data)

            # 리뷰
            review_data['title'] = detail_data['title']
            review_data['reviews'] = []
            for i in range(1, 6):  # 5개 페이지
                wd.get(detail_url + f"#{i}")
                time.sleep(2)  # 페이지 로딩 대기
                review_html = wd.page_source
                review_soup = BeautifulSoup(review_html, 'html.parser')
                page_reviews = review_soup.select('div.box-comment p')

                for review in page_reviews:
                    review_data['reviews'].append(review.text)
                    # 영화당 30개의 리뷰만 수집
                    if len(review_data['reviews']) >= 30:
                        break
                # 영화당 30개의 리뷰만 수집
                if len(review_data['reviews']) >= 30:
                    break
            review_data['reviews'] = review_data['reviews'][:30]  # 30개만 저장
            # ...
            result[cinemas.index(cinema)].append(detail_data)
            reviews[cinemas.index(cinema)].append(review_data)
        except Exception as e:  # 에러 발생 시
            print(f"An error occurred while processing {detail_url}: {e}")
            continue  # 에러 발생 시 해당 영화 건너뛰기
        print(reviews)

wd.close()  # 웹드라이버 종료

