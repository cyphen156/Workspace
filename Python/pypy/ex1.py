import csv
import matplotlib.pyplot as plt

fs = open("seoul.csv", encoding="cp949")
data = csv.reader(fs, delimiter=",")
header = next(data)
# print(header)
maxtmp = 0
maxdate = ""
result = []
day = ""
for row in data:
    if row[4] != "":
        day = row[2]
        if day.split('-')[1] == '01':
            tmp = float(row[4])
            if maxtmp < tmp:
                maxtmp = tmp
                maxdate = row[2]
                print(maxtmp, maxdate)

print("\n{}, {}".format(maxtmp, maxdate))
## plot = 꺾은선 / hist = 히스토그램 / boxplot = 상자그래프 / bar = 막대그래프 / barh = 수평막대
## pie = 타원 그래프 / scatter = 산점도
# # plt.title("hi")
# plt.plot(result, 'r.', label='result',  linestyle='--', )
# ## 'r = red' . = circle, ^ = triangle linetyle='dotted'
# plt.legend() ## label 표시기
# plt.show()
# hist(result, bins = 6) ## 가로 축 개수 = 6
fs.close()