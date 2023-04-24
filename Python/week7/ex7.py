from random import random

import matplotlib.pyplot as plt
import numpy as np
"""
abs = |(int array)|
"""
##sign 그래프
x = np.random.randint(10, 100, 200)
y = np.random.randint(10, 100, 200)
size = np.random.randint(len(x) )* 100

mask1 = abs(x) > 50
mask2 = abs(y) > 50

x = x[mask1 + mask2]

y = y[mask2 + mask1]

plt.scatter(x, y, s = size, c = x, cmap= 'jet', alpha=0.5)
plt.colorbar()
plt.show()