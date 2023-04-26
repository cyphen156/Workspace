import numpy as np
import matplotlib.pyplot as plt
import math
import random
import csv

fs = open('gender.csv', 'r', encoding='cp949')
data = csv.reader(fs)
header = next(data)
male = []
female = []
name = input('도시 이름을 입력하세요')
for row in data:
    if name in row[0]:
        for i in row[3:104]:
            male.append(-int(i.replace(',', '')))
            # print(i)
        for i in row[-1:-102:-1]:
            female.append(int(i.replace(',', '')))
            print(f"여성 {i}세: {i}")
female.reverse()
ages = list(range(0, 101))

print('\n', female)

plt.rc('font', size=16, family='Malgun Gothic')
plt.rcParams['axes.unicode_minus'] = False
plt.style.use('ggplot')
plt.barh(ages, male, color='blue', label='남성')
plt.barh(ages, female, color='red', label='여성')
plt.title(f'{name} 지역의 인구 구조')
plt.xlabel('인구수')
plt.ylabel('나이')
plt.legend()
plt.show()