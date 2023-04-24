import csv
import matplotlib.pyplot as plt


fs = open('gender.csv')
data = csv.reader(fs)
next(data)
res = []
max_baby = 0
max_city = ''


for row in data:
    male = []
    female = []
    city = input('학인할 도시를 입력하세요')
    if city in row[0]:
        for i in row[3:104]:
            male.append(int(i))
        for i in row[-1:100]:
            female.append(int(i))
    print(male)
    print(female)

