import random
import matplotlib.pyplot as plt

dice = []

for i in range(100000):
    dice.append(random.randint(1, 6))

plt.hist(dice)
plt.show()