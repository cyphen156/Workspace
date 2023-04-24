import random

import matplotlib.pyplot as plt
import numpy as np
# np.sub lib
"""
rand() == random.rand(5) -> 0~1 5value

choice(6, 10) -> range = 0~5 select 10 values
### = choice(range(1, 7), 10,replace = False)
if 중복 x => replace = False
p=[] == 확률
"""
x = []
y = []
size = []

for i in range(100):
    x.append(random.randint(10, 100))
    y.append(random.randint(10, 100))
    size.append(random.randint(10, 100))

plt.scatter(x, y, s = size, c=x, cmap='jet', alpha=0.7)
plt.colorbar()
plt.show()