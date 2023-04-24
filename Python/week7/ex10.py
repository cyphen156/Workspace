import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# idx = pd.date_range('1/1/2023', periods=8)
#
# df = pd.DataFrame(np.random.rand(8, 3), index=idx, columns=list('ABC'))
#
# print(idx, '\n', df, '\n', df['B'])
#
# df2 = df[df['B']>0.4]
#
# print(df2)


df = pd.read_csv('agg.csv', encoding='cp949', index_col=0)
print(type(df['2022년12월_계_총인구수']))
df = df.div(df['2022년12월_계_총인구수'], axis=0)

del df['2022년12월_계_총인구수'], df['2022년12월_계_연령구간인구수']

name = input('지역 입력해라')

a = df.index.str.contains(name)
df2 = df[a]

print(df2)


"""
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def str_to_int(val):
    return int(val.replace(',', ''))

converters = {
    col: str_to_int for col in range(1, 10)
}

df = pd.read_csv('agg.csv', encoding='cp949', index_col=0, converters=converters)
print(type(df['2022년12월_계_총인구수']))
df = df.div(df['2022년12월_계_총인구수'], axis=0)

del df['2022년12월_계_총인구수'], df['2022년12월_계_연령구간인구수']

name = input('지역 입력해라')

a = df.index.str.contains(name)
df2 = df[a]

print(df2)
"""