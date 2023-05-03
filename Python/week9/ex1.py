import csv

fs = open('subwayFee.csv')

data = csv.reader(fs)
next(data)

mx = 0;\\

for row in data:
    for i in range, (4, 8):
    print(row)

    if row[6] is not None:
    rate = row[4] / row[0]
    if