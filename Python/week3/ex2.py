ARRAY = []
# maxval = 0
# minval = None
"""
while True:
    temp = int(input('점수를 입력하시오 : '))
    if temp == 0:
        break
    ARRAY.append(temp)
    # if temp > maxval:
    #     maxval = temp
    # if (temp < minval) or (minval is None):
    #     minval = temp
print(ARRAY)
print("최대값은 {}이고, 최소값은 {}입니다".format(max(ARRAY), min(ARRAY)))
"""
##print(maxval, minval)

## 튜플과 리스트의 다른점은 무엇인가? ->> const list == final ==>> read only
# 그럼 튜플은 왜쓸까? => 데이터의 무결성을 보존하기 위해서 =>> 변형되면 안되는 자료가 존재한다!

#dictionary == object(key, val) ===> json
std1 = {
    '학번': [20170677, 12345678],
    '이름': ['오융택', 'ㅇㅇㅇ'],
    '학과': ['컴공', '소공'],
    '학년': ['4학년', '3학년']
}

## if not in dict keyward :: ++key, val
## if want to del key : del(dict[key])
print(std1)
std1['학번'] = 33333333
print(std1)
#dict key read
print(std1['학번']) #== std1.get('학번')
# ### 이 둘은 뭐가 다를까?
## 1번 방식은 키가 없으면 에러가 뜨고, 2번 방식은 아무것도 반환하지 않음 == return void
## 키가 있는지 없는지 찾고싶으면 [key] in dict

"""
key 출력 == dict.keys()
"""

print(std1.keys())
for key in std1.keys():
    print(key)

##EXAMPLE
mydict = {
    "강아지": 'dog',
    "고양이": 'cat',
    "새": 'bird',
    "코끼리": 'elephant'
}


while True:
    temp = input("동물이름(한글) : ")
    if temp == '끝':
        print("프로그램 종료")
        break
    if temp in mydict:
        print('{}는 영어로는 {}입니다'.format(temp, mydict[temp]))
    else:
        print("동물사전에 없습니다.")