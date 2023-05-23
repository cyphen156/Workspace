from bs4 import BeautifulSoup
import urllib.request

store_center = []
page = 1
for i in range(52):
    hollys_url = 'https://www.hollys.co.kr/store/korea/korStore2.do?pageNo=%d&sido=&gugun=&store=' % page
    html = urllib.request.urlopen(hollys_url)
    soup = BeautifulSoup(html, 'html.parser')
    tag_tbody = soup.find('tbody')
    for store in tag_tbody.find_all('tr'):
        store_td = store.find_all('td')
        store_center.append([store_td[0].string, store_td[1].string, store_td[3].string, store_td[5].string])
    page = page + 1
    print(store_center[i])



