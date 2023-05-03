import csv

fs = open('./subwayFee.csv')

data = csv.reader(fs)
next(data)

# 무임 승차 인원 = 6
mx = 0
mx_Station = [''] * 4
rate = 0
mx_res = [0] * 4
for row in data:
    for i in range(4, 8):
        row[i] = int(row[i])

    total = row[4] + row[6]
    # if row[6] != 0:
        # rate = row[4] / total
        # if rate > mx:
    if row[i] < mx_res[i-4]:
        mx_res[i-4] = row[i]
        mx_Station[i-4] = row[3] + " " + row[1]

print(mx, mx_Station)
