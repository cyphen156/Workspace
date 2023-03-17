money = int(input("교환 금액 입력 >>> "))
print("교환금액 : {}".format(money), "원")

m500 = money//500
money %= 500
print("500원", m500, "개")
m100 = money//100
money %= 100
print("100원", m100, "개")
m50 = money//50
money %= 50
print("50원", m50, "개")
m10 = money//10
money %= 10
print("10원", m10, "개")
