## numpy/pandas
from konlpy.tag import Kkma as kkma
import matplotlib.pyplot as plt

t = []
p2 = []
p3 = []

for i in range(0, 50, 2):
    res = float(i/10)
    t.append(res)
    p2.append(res ** 2)
    p3.append(res ** 3)
print(t, p2, p3)

plt.plot(p3, t, 'r')
plt.plot(p3, p2, 'b')
plt.plot(p3, p3, 'g')
## = plt.plot(t, t, 'r--', t, p2, 'bs', t, p3, 'g^')
##            x, y, RGB
plt.show()