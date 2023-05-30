from bs4 import BeautifulSoup
import urllib.request
import pandas as pd

theaters_center = {}
CGV_url = 'https://www.cgv.co.kr/'
html = urllib.request.urlopen(CGV_url)
soup = BeautifulSoup(html, 'html.parser')
movie_chart = soup.find('div', class_='swiper movieChart_list')
movie_slides = movie_chart.find_all('div', class_='swiper-slide swiper-slide-movie')

# 각 영화 정보 추출
movies = []
for index, slide in enumerate(movie_slides, start=1):
    movie = {}
    movie['rank'] = index
    movie['img'] = slide.find('img')['src']
    movie['name'] = slide.find('strong', class_='movieName').text
    booking_rate_text = slide.find('span', text=lambda x: x and "예매율" in x).text
    # 예매율에서 숫자 부분만 추출
    movie['booking_rate'] = float(booking_rate_text.replace('예매율 ', '').replace('%', ''))
    movies.append(movie)

for i in movies:
    print(i)

# csv 파일로 저장
df = pd.DataFrame(movies)

df.to_csv('movies.csv', index=True, encoding='cp949')
print("CSV저장 완료")