## 비만도 지수 구하기
"""
1. 몸무게 입력(kg)
2. 키 (cm)
3. bmi 지수 연산 == kg/m**
소숫점 이하 2자리 표현
"""

print("몸무게 입력(kg)")
weight = int(input())
print("키 입력(cm)")
height = float(input())/100

bmi = weight/(height)**2
print("bmi = {:.2f}".format(bmi)) ## index:format
print("bmi = %.2f" % bmi) ##같은문장