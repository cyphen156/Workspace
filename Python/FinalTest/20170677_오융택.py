from selenium import webdriver
from bs4 import BeautifulSoup
from selenium.common import NoSuchElementException
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
import re
import pandas as pd
import time
import os

# CGV 크롤링
def crawl_cgv(url):
    # 현재 상영중인 영화 개수 10개 뽑아냄 이유는 롯데시네마가 14개까지밖에 없어서 10개로 딱 자름
    # CGV는 평점데이터가 없음-_-
    # 골든 에그는 기대-실관람 후기 0~100점인데 대부분 영화가 95점 이상이라 유의미한 가치를 지니지 않음
    movie_elements = soup.select('div.box-image > a')[:10]
    midx_values = [element.get('href').split('=')[-1] for element in movie_elements]
    print(f"From {url}, got {len(midx_values)} midx values.")
    print(midx_values)
    # 각 영화의 상세 페이지로 이동
    for midx in midx_values:
        detail_url = url + '/detail-view/?midx=' + midx
        wd.get(detail_url)

        # 페이지 로딩 완료 대기
        wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.box-contents')))
        time.sleep(1)
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
            genre_element = box_contents.select_one('dt:-soup-contains("장르")')
            if genre_element:
                genre = genre_element.find_next_sibling().text.strip()
                detail_data['genre'] = genre if genre else None
            else:
                detail_data['genre'] = None

            # 성별 예매 분포
            sex_distribution = detail_soup.select_one('div#jqplot_sex')
            gender_distribution = detail_soup.select('div#jqplot_sex span.jqplot-donut-series.jqplot-data-label')
            detail_data['gender_distribution'] = {gender.text.split()[0]: gender.text.split()[1] for gender in
                                                  gender_distribution}

            # 연령별 예매 분포
            age_distribution = detail_soup.select('div#jqplot_age div.jqplot-point-label.jqplot-series-0')
            detail_data['age_distribution'] = {f"{10 * i + 10}대": age.text for i, age in
                                               enumerate(reversed(age_distribution))}
            print(detail_data)

            # 리뷰
            review_data['title'] = detail_data['title']
            review_data['reviews'] = []
            review_page_links = [a['href'] for a in detail_soup.select('#paging_point > li > a')][:5]  # 상위 5개 페이지 링크

            for i in range(1, 6):  # 5개 페이지
                try:
                    pagination_button = wd.find_element(By.XPATH,
                                                        '//ul[@id="paging_point"]/li/a[contains(@href, "#' + str(
                                                            i) + '")]')
                    # a 태그 클릭
                    pagination_button.click()  # 페이지 로딩 완료 대기
                    wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.box-comment p')))
                    time.sleep(1)  # 페이지 로딩 대기
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
                except Exception as e:  # 특정 페이지에 접근 실패 시 예외 처리
                    print(f"An error occurred while processing page {i} of {detail_url}: {e}")
                    continue

            review_data['reviews'] = review_data['reviews'][:30]  # 30개만 저장

            result[cinemas.index(cinema)].append(detail_data)
            reviews[cinemas.index(cinema)].append(review_data)
        except Exception as e:  # 에러 발생 시
            print(f"An error occurred while processing {detail_url}: {e}")
            continue  # 에러 발생 시 해당 영화 건너뛰기

# 롯데시네마 크롤링
def crawl_lotte(url):
    wd.get(url)
    time.sleep(1)
    button = wd.find_element(By.CLASS_NAME, "btn_txt_more")
    button.click()  # 페이지 로딩 완료 대기
    wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.inner a.btn_col3.ty3')))
    time.sleep(1)
    print('로딩로딩')

    html = wd.page_source
    soup = BeautifulSoup(html, 'html.parser')

    movie_elements = soup.select(
        'div.inner a.btn_col3.ty3')
    midx_values = []
    cnt = 0
    for element in movie_elements:
        if cnt > 20:
            break
        link = element.get('href')
        if "MovieDetailView" in link:
            movie_id = link.split('=')[-1]
            midx_values.append(movie_id)
        cnt += 1
    print(f"From {url}, got {len(midx_values)} midx values.")
    print(midx_values)

    # 각 영화의 상세 페이지로 이동
    for midx in midx_values:
        detail_url = 'https://www.lottecinema.co.kr/NLCHS/Movie/MovieDetailView?movie=' + midx
        wd.get(detail_url)

        # 페이지 로딩 완료 대기
        time.sleep(1)
        detail_html = wd.page_source
        detail_soup = BeautifulSoup(detail_html, 'html.parser')

        detail_data = {}
        review_data = {}
        try:  # 예외 처리 시작
            # 상세 정보 가져오기
            box_contents = detail_soup.select_one('div.detail_top_wrap.new22')
            # 영화 제목, 평점, 전체 예매율, 장르
            detail_data['title'] = box_contents.select_one('div.tit_info > strong').text.strip('()')
            detail_data[' grade_point'] = box_contents.select_one('ul.detail_info1 > li.sub_info1 > strong.txt_ic_score.ty2 > strong').text.strip('()')
            detail_data['reservation_rate'] = box_contents.select_one('li.sub_info2 > strong').text.strip('()')
            genre_release_info = box_contents.select_one('ul.detail_info2 > li.sub_info1 > strong').text.strip('()')
            genre_release_split = genre_release_info.split('/')
            detail_data['genre'] = genre_release_split[0].strip()

            # 성별 예매 분포
            sex_distribution = detail_soup.select('div.bx_graph01 dl > dd')
            detail_data['gender_distribution'] = {
                dist.find_previous_sibling('dt').text: dist.select_one('strong').text for dist in sex_distribution
            }

            # 연령별 예매 분포
            age_distribution = detail_soup.select('div.bx_graph02 dl > dd')
            detail_data['age_distribution'] = {
                dist.find_previous_sibling('dt').text: dist.select_one('strong').text for dist in age_distribution
            }

            print(detail_data)

            # '평점 및 관람평' 탭 선택
            wd.find_elements(By.CSS_SELECTOR, 'button.tab_tit')[1].click()  # '평점 및 관람평' 탭 클릭
            time.sleep(1)

            review_data['title'] = detail_data['title']
            review_data['reviews'] = []

            # '펼쳐보기' 버튼 두 번 클릭
            for _ in range(2):
                try:
                    # button2 = wd.find_elements(By.CSS_SELECTOR, 'button.btn-onair.btnOnAir')
                    # button2[0].click()  # 페이지 로딩 완료 대기
                    # time.sleep(2)
                    show_more_buttons = wd.find_elements(By.XPATH, '//button[@id="btn_review_more"]/span[text()="펼쳐보기"]')
                    if show_more_buttons:
                        # 요소가 화면에 표시되도록 스크롤링
                        actions = ActionChains(wd)
                        actions.move_to_element(show_more_buttons[0]).perform()
                        time.sleep(1)

                        # 버튼 클릭
                        show_more_buttons[0].click()
                        time.sleep(1)
                    else:
                        print("No more 'Show more' buttons.")
                        break
                except Exception as e:  # 버튼이 더 이상 없는 경우 예외 처리
                    print("No more 'Show more' buttons.")
                    break

            # 가져온 리뷰 데이터 파싱
            review_elements = wd.find_elements(By.CSS_SELECTOR, 'ul.review_con_list li')
            for element in review_elements:
                review_text = element.find_element(By.CSS_SELECTOR, 'div.review_info').text
                try:
                    score = element.find_element(By.CSS_SELECTOR, 'span.gradenum').text
                except NoSuchElementException:
                    score = "No score"

                review_data['reviews'].append({
                    'review_text': review_text,
                    'score': score
                })
            review_data['reviews'] = review_data['reviews'][:30]  # 30개만 저장

            result[cinemas.index(cinema)].append(detail_data)
            reviews[cinemas.index(cinema)].append(review_data)



        except Exception as e:  # 에러 발생 시
            print(f"An error occurred while processing {detail_url}: {e}")
            continue  # 에러 발생 시 해당 영화 건너뛰기

def crawl_mega(url):
    button2 = wd.find_elements(By.CSS_SELECTOR, 'button.btn-onair.btnOnAir')
    button2[0].click()  # 페이지 로딩 완료 대기
    time.sleep(1)
    print('로딩로딩로딩')

    html = wd.page_source
    soup = BeautifulSoup(html, 'html.parser')

    movie_elements = soup.select(
        'ol.list > li > div.movie-list-info > div.movie-score > a')
    midx_values = [element.get('data-no') for element in movie_elements]
    print(midx_values)

    # 각 영화의 상세 페이지로 이동
    for midx in midx_values:
        detail_url = url + '-detail?rpstMovieNo=' + midx
        wd.get(detail_url)

        # 페이지 로딩 완료 대기
        time.sleep(1)
        detail_html = wd.page_source
        detail_soup = BeautifulSoup(detail_html, 'html.parser')

        detail_data = {}
        review_data = {}
        try:  # 예외 처리 시작
            # 상세 정보 가져오기
            box_contents = detail_soup.select_one('div.movie-detail-cont')
            # 영화 제목, 평점, 전체 예매율, 장르
            detail_data['title'] = box_contents.select_one('p.title').text.strip('()')
            detail_data['grade_point'] = box_contents.select_one(
                'div.info > div.score > div.number.gt > p.before > em').text.strip('()')
            detail_data['reservation_rate'] = box_contents.select_one('div.info > div.rate > p.cont').text
            reservation_rate_text = box_contents.select_one('div.info > div.rate > p.cont').text.strip('()')
            detail_data['reservation_rate'] = reservation_rate_text.split('(')[1]
            genre_element = wd.find_element(By.CSS_SELECTOR,
                'div.inner-wrap > div.movie-info.infoContent > div.line > p:nth-of-type(1)')
            wd.execute_script("arguments[0].scrollIntoView();", genre_element)
            time.sleep(1)

            genre_release_info = genre_element.text
            genre = genre_release_info.split(':')[1].split('/')[0].strip()
            detail_data['genre'] = genre

            print(detail_data)

            # 메가박스는 성별, 나이별 관객 비율을 제공하지 않습니다.

            wd.find_element(By.LINK_TEXT, "실관람평").click()
            # 리뷰
            review_data['title'] = detail_data['title']
            review_data['reviews'] = []
            for page in range(1, 4):
                try:
                    # 페이지 로딩 완료 대기
                    time.sleep(1)

                    # 페이지의 모든 리뷰 가져오기
                    review_elements = wd.find_elements(By.CSS_SELECTOR,
                                                       "div.movie-idv-story.oneContent > ul > li.type01.oneContentTag > div.story-area > div.story-wrap.review > div.story-cont > div.story-txt")

                    # 각 리뷰를 리스트에 추가
                    for review in review_elements:
                        review_data['reviews'].append(review.text)

                    # 다음 페이지가 있으면 이동
                    next_page_num = page + 1
                    next_page = wd.find_elements(By.CSS_SELECTOR, f'nav.pagination > a[title="{next_page_num}페이지보기"]')
                    if len(next_page) > 0:  # 다음 페이지가 있는 경우
                        next_page[0].click()
                    else:  # 다음 페이지가 없는 경우
                        break
                except Exception as e:
                    print(f"An error occurred while processing page {page}: {str(e)}")

            # 리뷰 저장
            result[cinemas.index(cinema)].append(detail_data)
            reviews[cinemas.index(cinema)].append(review_data)
        except Exception as e:  # 에러 발생 시
            print(f"An error occurred while processing {detail_url}: {e}")
            continue  # 에러 발생 시 해당 영화 건너뛰기



wd = webdriver.Chrome(service=Service('./WebDriver/chromedriver.exe'))
base_dir = os.getcwd()

cinemas = ['http://www.cgv.co.kr/movies', 'https://www.lottecinema.co.kr/NLCHS/Movie/List?flag=1', 'https://megabox.co.kr/movie'] # 영화회사 리스트
         # 18개 18개 18개
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
    if 'cgv' in cinema:
        crawl_cgv(cinema)
        print(reviews)
    elif 'lotte' in cinema:
        crawl_lotte(cinema)
    elif 'mega' in cinema:
        crawl_mega(cinema)
        print(reviews)


# # CSV 파일로 결과 저장
# for i, cinema in enumerate(cinemas):
#     result_file_name = f"{cinema.split('.')[1]}.csv"
#     review_file_name = f"{cinema.split('.')[1]}_reviews.csv"
#
#     # 결과 데이터프레임 생성
#     result_df = pd.DataFrame(result[i], columns=['Title', 'Grade Point', 'Reservation Rate', 'Genre'])
#     review_dfs = []  # 빈 리스트 생성
#
#     # 리뷰 데이터프레임 생성
#     for review_data in reviews[i]:
#         review_dfs.append(pd.DataFrame(review_data['reviews'], columns=['Review Text', 'Score']))
#
#     review_df = pd.concat(review_dfs, ignore_index=True)  # 데이터프레임 합치기
#
#     # 결과를 CSV 파일로 저장 (cp949 인코딩)
#     result_df.to_csv(result_file_name, index=False, encoding='cp949')
#     review_df.to_csv(review_file_name, index=False, encoding='cp949')

wd.close()  # 웹드라이버 종료

