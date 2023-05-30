import pandas as pd

# red_df = pd.read_csv('./data/winequality-red.csv', sep=';', header=0, engine='python')
# white_df = pd.read_csv('./data/winequality-white.csv', sep=';', header=0, engine='python')
#
# red_df.to_csv('./data/winequality-red2.csv', index=False)
# white_df.to_csv('./data/winequality-white2.csv', index=False)

# red_df = pd.read_csv('./data/winequality-red2.csv')
# red_df.insert(0, column='type', value='red')
#
# white_df = pd.read_csv('./data/winequality-white2.csv')
# white_df.insert(0, column='type', value='white')
#
# print(red_df.shape)
# print(white_df.shape)
#
# wine = pd.concat([red_df, white_df])
# print(wine.head())
# print(wine.shape)
#
# wine.to_csv('./data/wine.csv', index=True, encoding='cp949')

wine = pd.read_csv('./data/wine.csv')

wine.columns = wine.columns.str.replace(' ', '_')
### 기술 통계를 조회하는 방법 == describe / mean / std

wine.to_csv('./data/wine2.csv', index=True)



"""
##

pip install statsmodels

##
"""