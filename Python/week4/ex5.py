import math
import csv
import tracemalloc

tracemalloc.start()
fs = open("seoul.csv", "r", encoding="cp949")

data = csv.reader(fs)
header = next(data)
print(data)
print(header)
i = 0
strmax = float(-234.0)
maxdate = ""

coldestday = ""
strmin = float(math.inf)

tempbtwday = ""
tempbtw = float(-math.inf)
for row in data:
    i += 1
    if row[4] == "" or row[3] == "":
        continue ## else row[3] = None
    if strmax <= float(row[4]):
        maxdate = row[0]
        strmax = float(row[4])
    if strmin >= float(row[3]):
        strmin = float(row[3])
        coldestday = row[0]
    if  tempbtw < (float(row[4]) - float(row[3])):
        tempbtw = (float(row[4]) - float(row[3]))
        tempbtwday = row[0]
    if i == 100:
        print("***************************************************************")
        i = 0
    print(row)



print("fs : 서울 기상 관측 이래 가장 기온이 높았던 날은 {}일이고, 온도는 {}도 였습니다.".format(maxdate, strmax))
print("fs : 서울 기상 관측 이래 가장 기온이 낮았던 날은 {}일이고, 온도는 {}도 였습니다.".format(coldestday, strmin))
print("fs : 서울 기상 관측 이래 가장 일교차가 컸던 날은 {}일이고, 온도는 {}도 였습니다.".format(tempbtwday, tempbtw))
fs.close()