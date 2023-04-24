#numpy
import matplotlib.pyplot as plt
import numpy as np
t = np.arange(0, 5, 0.2)
print(type(t)) # == np.n dimension array
plt.plot(t, t, 'r--')
plt.plot(t, t**2, 'bs')
plt.plot(t, t**3, 'g^')
plt.show()