from selenium import webdriver
from bs4 import BeautifulSoup
import time
import pandas as pd

wd = webdriver.Chrome('./webDriver/chromedriver.exe')

index = 0;
result = []
for index in range(1, 11):
    wd.get('https://www.coffeebeankorea.com/store/store.asp')

    time.sleep(1)
    wd.execute_script('storePop2(%d)'% index)
    time.sleep(1)
    html = wd.page_source
    soup = BeautifulSoup(html, 'html.parser')
    store_name = soup.select('div.store_txt>h2')
    if len(store_name) == 0:
        print('검색 결과 없음')
        continue
    store_name = store_name[0].string
    store_info = soup.select('div.store_txt>table.store_table>tbody>tr>td')
    store_address_list = list(store_info[2])
    store_address = store_address_list[0]
    store_phone = store_info[3].string
    result.append([store_name, store_address, store_phone])

print(result)

