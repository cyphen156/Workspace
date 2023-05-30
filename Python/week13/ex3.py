import seaborn as sns
import pandas as pd

# titanic = sns.load_dataset('titanic')
# titanic.to_csv('./data/titanic.csv')

titanic = pd.read_csv('./data/titanic.csv', encoding='cp949')

# print(titanic.isnull().sum())

titanic['age'] = titanic['age'].fillna(titanic['age'].median())
titanic['embarked'] = titanic['embarked'].fillna('S')
titanic['embark_town'] = titanic['embark_town'].fillna('Southampton')
titanic['deck'] = titanic['deck'].fillna('C')
# print(titanic.isnull().sum())



import matplotlib.pyplot as plt
# titanic.info()
#
# f, ax = plt.subplots(1, 2, figsize=(10, 5))
# titanic['survived'][titanic['sex'] == 'male'].value_counts().plot.pie(explode=[0, 0.1], autopct='%1.1f%%', ax=ax[0], shadow=True)
# titanic['survived'][titanic['sex'] == 'female'].value_counts().plot.pie(explode=[0, 0.1], autopct='%1.1f%%', ax=ax[1], shadow=True)
#
# ax[0].set_title('survived (Male)')
# ax[1].set_title('survived (Female)')
# plt.show()
#
# sns.countplot(x = 'pclass', hue='survived', data=titanic)
# plt.title('pclass vs survive')
# plt.show()

titanic2 = titanic[titanic.columns.difference(['sex', 'embarked', 'class', 'who', 'deck', 'embark_town', 'alive'])]
titanic2_corr = titanic2.corr(method='pearson')
print(titanic2_corr)
titanic2_corr.to_csv('./data/titanic_corr.csv', index=True)

# sns.pairplot(titanic2, hue='survived')
sns.catplot(x = 'pclass', y = 'survived', hue='sex', data=titanic, kind='point')
plt.show()
