from bs4 import BeautifulSoup
import urllib.request

theaters_center = {}
CGV_url = 'http://www.cgv.co.kr/theaters/'
html = urllib.request.urlopen(CGV_url)
soup = BeautifulSoup(html, 'html.parser')
sect_city = soup.find('div', class_='sect-city') #지역별 크롤링
city_ul = sect_city.find('ul')
city_li = city_ul.find_all('li')

for theaters in sect_city.find_all('ul'):
    theaters_a = theaters.find_all('a')
print(theaters_center)



