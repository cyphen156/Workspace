def calc(num):
    result = []
    for i in range(num):
        result.append([])
        for j in range(num):
            if i > j:
                result[i].append(i**2 - j**2 + j)
            else:
                result[i].append(i + j + 1)

        print(result[i])


calc(5)
"""
    123     1234        00  01  02  03  04          1   2   3   4   5
    894     1213145     10  11  12  13  14          16  17  18  19  6
    765     1116156     20  21  22  23  24          15  24  25  20  7
            10987       30  31  32  33  34          14  23  22  21  8
                        40  41  42  43  44          13  12  11  10  9
"""