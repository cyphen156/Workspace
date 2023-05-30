import pandas as pd
from statsmodels.formula.api import ols, gls

wine = pd.read_csv("./data/wine2.csv")

#linear logistics analystics
#종속 변수 #독립 변수
Rformula = 'quality ~ fixed_acidity+volatile_acidity+' \
           'citric_acid+residual_sugar+chlorides+' \
           'free_sulfur_dioxide+total_sulfur_dioxide+density+pH+sulphates+alcohol'

regression_result = ols(Rformula, data=wine).fit()
# print(regression_result.summary())

sample1 = wine[wine.columns.difference(['quality', 'type'])]
sample1 = sample1[:5][:]

sample1_predict = regression_result.predict(sample1)
print(sample1_predict)
print(wine[:5]['quality'])

data = {
    'fixed_acidity': [8.5, 8.1],
    'volatile_acidity': [0.8, 0.5],
    'citric_acid': [0.3, 0.4],
    'residual_sugar': [6.1, 5.8],
    'chlorides': [0.055, 0.04],
    'free_sulfur_dioxide': [30.0, 31.0],
    'total_sulfur_dioxide': [98.0, 99.0],
    'density': [0.996, 0.91],
    'pH': [3.25, 3.01],
    'sulphates': [0.4, 0.35],
    'alcohol': [9.0, 0.88]
    }

sample2 = pd.DataFrame(data, columns=sample1.columns[2:])
print(sample2)

sample2_predict = regression_result.predict(sample2)

import seaborn as sns
import matplotlib.pyplot as plt
red_wine_quality = wine.loc[wine['type']=='red', 'quality']
white_wine_quality = wine.loc[wine['type']=='white', 'quality']
sns.set_style('dark')
sns.displot(red_wine_quality, kde=True, color='red', label='red wine')
sns.displot(white_wine_quality, kde=True, color='blue', label='white wine')
plt.title('quality of wine white/red')
plt.legend()
plt.show()