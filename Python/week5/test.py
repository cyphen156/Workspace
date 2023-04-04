def calc(num):
    result = []
    for i in range(num):
        result.append([])
        for j in range(num):
            result[i].append((i + j))
        print(result[i])


calc(3)
"""
    123     1234
    894     1213145
    765     1116156
            10987
"""
