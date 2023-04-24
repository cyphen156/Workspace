import csv
import matplotlib.pyplot as plt

EEE = {
    'size': [1345, 5564, 122, 30],
    'label': ['a', 'b', 'ab', 'o'],
    'color': ['hotpink', 'skyblue', 'black', 'green']
}

plt.axis('gender')
plt.pie(EEE.size, labels=EEE.label, colors=EEE.color, explode=(0, 0, 0.1, 0))
