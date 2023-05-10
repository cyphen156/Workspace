"""
node = 'blog, news, cafe ...'
검색어 = input()

"""
import datetime
import json
import os
import sys
import urllib.request
client_id = '_1lxr4EpON5EFHjttfGV'
client_secret = 'fXGSpjYenD'
# encText = urllib.parse.quoto()

def getRequestUrl(Url):
    req = urllib.request.Request(Url)
    req.add_header('X-Naver-Client-Id', client_id)
    req.add_header('X-Naver-Client-Secret', client_secret)
    try:
        res = urllib.request.urlopen(req)
        if res.getcode() == 200:
            print('요청 정상처리')
            print('[%s] Url req Success' % (datetime.datetime.now()))
            return res.read().decode('utf-8')
        # elif res.getcode(300):
        #     print('추가 요구')
        # elif res.getcode(400):
        #     print('client err')
        # else :
        #     print('server Err')
    except Exception as e:
        print(e)
        print('[%s] Url req Err' % (datetime.datetime.now()))
        return None
    
def getNaverSearch(node, srcText, page_start, display):
    base = 'https://openapi.naver.com/v1/search'
    node='/%s.json' % node
    parameters = '?query=%s&start=%s&display=%s' % (urllib.parse.quote(srcText), page_start, display)
    url = base + node + parameters

    resDecode = getRequestUrl(url)

    if resDecode == None:
        return None
    else:
        return json.loads(resDecode)
    
def getPostData(i, Jresult, cnt):
    title = i['title']
    discription = i["discription"]
    org_link = i['originallint']
    link = i["link"]
    pDate = datetime.datetime.strptime(i["pubDate"], "%a, %d %b %Y %H:%M:%S")
    pDate = pDate.strftime("%Y-%M-%D %H:%M:%S")
    Jresult.append(
        {'cnt':cnt,
        'title':title,
        'discription':discription,
        'org_link':org_link,
        'link':link
        })
    return

def Main():
    node = 'news'
    srcText = input("검색어 입력")
    cnt = 0
    Jresult = []

    jresponse = getNaverSearch(node=node, srcText=srcText, page_start = 1, display = 100)
    total = jresponse['total']

    while jresponse is not None and jresponse['display'] != 0:
        for i in jresponse['items']:
            cnt += 1
            getPostData(i, Jresult, cnt)

        start = jresponse["start"] + jresponse["display"]
        jresponse = getNaverSearch(node=node, srcText=srcText, start=start, display=100)

    print('전체 검색 건수: %d 건' % total)

    with open("%s_naver_%s.json" % (srcText, node), "w", encoding='utf-8') as outfile:
        jsonFile = json.dumps(Jresult, indent=4, sort_keys=True, ensure_ascii=False)

        outfile.write(jsonFile)

    print('가져온 데이터수 : %d 건' % total)
    print('%s_naver_%s.json saved' %(srcText, node))

# if __name__ == "__main__": 
    

# getRequestUrl('https://openapi.naver.com/v1/search/news.json?query=%EC%A3%BC%EC%8B%9D&display=10&start=1&sort=sim')
# print(getRequestUrl("https://openapi.naver.com/v1/search/news.xml?query=%EC%A3%BC%EC%8B%9D&display=10&start=1&sort=sim"))
