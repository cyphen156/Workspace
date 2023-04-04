import random
import matplotlib.pyplot as plt
import numpy as np

result = []
for i in range(13):
    result.append(random.randint(1, 1000))

res1 = np.array(result)
print("1/4 : " + str(np.percentile(res1, 25)))
print("2/4 : " + str(np.percentile(res1, 50)))
print("3/4 : " + str(np.percentile(res1, 75)))

print(sorted(result))
plt.boxplot(result)
plt.show()