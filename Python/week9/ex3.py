import csv
import matplotlib.pyplot as plt
fs = open('./subwayFee.csv')

data = csv.reader(fs)
next(data)
label = ['유임승차', '유임하차', '무임승차', '무임하차']

# 무임 승차 인원 = 6
mx = 0
mx_Station = [''] * 4
rate = 0
mx_res = [0] * 4
for row in data:
    for i in range(4, 8):
        row[i] = int(row[i])

    plt.rc('font', family = 'Malgun Gothic')
    plt.title(row[3] + row[1])
    plt.pie(row[4:8], labels = label, autopct='%.1f%%')
    plt.axis('equal')
    plt.savefig('C:/Workspace/python/week9/plt/' + row[3] + " " + row[1] + 'png')
    plt.clf()
    # plt.show()

print('end')
#     total = row[4] + row[6]
#     # if row[6] != 0:
#         # rate = row[4] / total
#         # if rate > mx:
#     if row[i] > mx_res[i-4]:
#         mx_res[i-4] = row[i]
#         mx_Station[i-4] = row[3] + " " + row[1]
# for i in range(4):
#     print(mx_res[i], mx_Station[i])
#
