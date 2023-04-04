import matplotlib.pyplot as plt
import csv
f = open('seoul.csv')

data = csv.reader(f)
header = next(data)

result =[]
for row in data:
    if row[4] != '':
        result.append(float(row[4]))

print(len(result))
plt.plot(result)
plt.show()