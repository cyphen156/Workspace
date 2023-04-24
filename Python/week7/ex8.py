import numpy as np
import matplotlib.pyplot as plt
import csv, math

fs = open('agg.csv')
data = csv.reader(fs)
next(data)
data = list(data)
minVal = math.inf
result_name = ''
result = 0
male = []
female = []
home = []
name = input("살고 있는 동네가 어디니?")
away = []
##ValueError: invalid literal for int() with base 10: '7,928'

for row in data:
    if name in row[0]:
        home = np.array(row[3:], dtype=int)

for row in data:
    if int(row[2]) == 0:
        continue
    away = np.array(row[3:], dtype=int)/int(row[2])
    s = np.sum(abs(home - away))
    if minVal > s:
        minVal = s
        result_name = row[0]
        result = away

plt.style.use('ggplot')
plt.rc('font', family="Malgun Gothic")
plt.title(name + '지역의 인구구조')
plt.plot(home, label=name)
plt.plot(result, label=result_name)
plt.legend()
plt.show()