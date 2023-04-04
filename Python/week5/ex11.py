# 내 생일의 기온데이터 그래프 그리기
import matplotlib.pyplot as plt
import csv
f = open('seoul.csv')

data = csv.reader(f)
header = next(data)

month = [[], [], [], [], [], [], [], [], [], [], [], []]
for row in data:
    year = row[0].split('-')[0]
    if row[4] == '' or int(year) != 2022:
        continue
    idx = int(row[0].split('-')[1])
    month[idx-1].append(float(row[4]))

plt.boxplot(month)
plt.show()
