import csv
import matplotlib.pyplot as plt


fs = open('gender.csv')
data = csv.reader(fs)
next(data)
res = []
max_baby = 0
max_city = ''



while True:
    dong = input('검색하고 싶은 동을 입력하세요')
    male = []
    female = []
    if dong == 'end':
        break
    for row in data:
        if '동' not in row[0].split(' ')[2] or dong not in row[0].split(' ')[2]:
            continue
        elif dong in row[0]:
            print(row)
            ## 3분할 한 다음에 동 이 들어간 컬럼을 찾아내야하는데 어떻게할까?

            #print(i, end=' ')
            for i in row[3:104]:
                male.append(int(i.replace(',', '')))
            for i in row[-1:-100:-1]:
                female.append(int(i.replace(',', '')))
    print(len(male))
    print(len(female))
plt.style.use('ggplot')
plt.rc('font', family = 'malgun gothic')
plt.figure(figsize=(10, 5))
plt.title(dong + ' 지역의 인구구조')
plt.plot(res)
plt.show()