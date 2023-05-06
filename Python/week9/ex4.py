import csv
from matplotlib import font_manager, rc
import matplotlib.pyplot as plt
font_path = "C:/Windows/Fonts/malgun.ttf"
font = font_manager.FontProperties(fname = font_path).get_name()
rc('font', family = font)

fs = open('subwaytime.csv')
data = csv.reader(fs)

next(data)
next(data)
mx = [[0, 0] for i in range(24)]
mx_stat = [['', ''] for i in range(24)]

t = input('어떤의 시간대별 승하차 인원이 궁금한가요?')

for row in data:
    row[4:] = map(int, row[4:])

    if row[3] == t:
    for i in range(24):
        a = row[i * 2 + 4]
        b = row[i * 2 + 5]

        if a > mx[i][0]:
            mx[i][0] = a
            mx_stat[i][0] = row[3]
        if b > mx[i][1]:
            mx[i][1] = b
            mx_stat[i][1] = row[3]

for i in range(24):
    print(mx_stat[i], mx[i])
hours = list(range(24))
a_values = [x[0] for x in mx]
b_values = [x[1] for x in mx]

plt.style.use('ggplot')
plt.plot(hours, a_values, color='red', label='승차 인원')
plt.plot(hours, b_values, color='blue', label='하차 인원')

plt.rc('font', family="Malgun Gothic")
plt.rcParams['axes.unicode_minus'] = False
plt.title('시간대별 가장 많은 승하차 인원 역')
plt.xlabel('시간 (시간대)')
plt.ylabel('인원 수')
plt.legend()
plt.xticks(hours)
plt.show()
#     res[0].append(row[10])
#     res[1].append(row[11])
#     print(res)
#
# print(res)