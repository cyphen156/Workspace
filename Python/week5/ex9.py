# 내 생일의 기온데이터 그래프 그리기
import matplotlib.pyplot as plt
import csv
f = open('seoul.csv')

data = csv.reader(f)
header = next(data)

result = []
high = []
low = []
for row in data:
    birth = row[0].split('-')
    if row[4] == '' or row[3] == '' or int(birth[0]) < 1997:
        continue
    if birth[1] == '01' and birth[2] == '03':
        high.append(float(row[4]))
        low.append(float(row[3]))

print(len(result))
plt.figure(figsize=(10, 3))
plt.rc('font', family='Malgun Gothic')
plt.rcParams['axes.unicode_minus'] = False
plt.title("내 생일날의 최고 기온과 최저기온")
plt.hist(high, bins=100, color="crimson", label="최고기온")
plt.hist(low, bins=100, color="skyblue", label=" 최저기온")
plt.show()
