from selenium import webdriver
from bs4 import BeautifulSoup
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import pandas as pd

wd = webdriver.Chrome('./webDriver/chromedriver.exe')

CGV_url = 'http://www.cgv.co.kr/theaters/'
wd.get(CGV_url)
wait = WebDriverWait(wd, 10)
element = wait.until(EC.presence_of_element_located((By.CLASS_NAME, 'sect-city')))

html = wd.page_source
soup = BeautifulSoup(html, 'html.parser')

city_list = soup.select('div.sect-city > ul > li')
print(city_list)
theaters = {}

for city in city_list:
    city_name = city.find('a').get_text().strip()
    theater_ul = city.find('div').find('ul')
    theater_list = theater_ul.find_all('li')

    city_theaters = []

    for theater in theater_list:
        theater_info = {}
        theater_name = theater.find('a').get_text().strip()
        theater_link = theater.find('a')['href']
        theater_info['Theater'] = theater_name
        theater_info['Link'] = 'http://www.cgv.co.kr' + theater_link
        city_theaters.append(theater_info)

    theaters[city_name] = city_theaters

    for city, city_theaters in theaters.items():
        print(city)
        for theater in city_theaters:
            print('\t', theater)

data = []
for city, theaters_list in theaters.items():
    for theater in theaters_list:
        theater['city'] = city
        data.append(theater)

# Creating a dataframe
df = pd.DataFrame(data)

df.to_csv('theaters.csv', index=True, encoding='cp949')
print("CSV저장 완료")
wd.close()


