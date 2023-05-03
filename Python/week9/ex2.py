import csv

fs = open('subwayFee.csv')

data = csv.reader(fs)
next(data)

# 무임 승차 인원 = 6
mx = 0
mx_Station = ''
rate = 0
array = []
for row in data:
    for i in range(4, 8):
        row[i] = int(row[i])

    total = row[4] + row[6]
    # if row[6] != 0:
        # rate = row[4] / total
        # if rate > mx:
    if mx < total:
        mx = total
        mx_Station = row[3]


print(mx, mx_Station)