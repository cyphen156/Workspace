## function example
import math


#
# def plus(v1, v2):
#     result = v1 + v2
#     return result
# def minus(v1, v2):
#     return v1-v2
# def mulitply(v1, v2):
#     return v1 * v2
# def divide(v1, v2):
#     if v2 == 0:
#         print("value {} is not divideable".format(v2))
#         return 0
#     return v1/v2
#
# def calc():
#     v1 = int(input())
#     v2 = int(input())
#     op = input()
#     if op == '+':
#         return plus(v1, v2)
#     elif op == '-':
#         return minus(v1, v2)
#     elif op == '*':
#         return mulitply(v1, v2)
#     else:
#         return divide(v1, v2)
#
# print(calc())


###example
def circle_area(r):
    return r * r * math.pi


def circle_length(r):
    return 2 * r * math.pi


while True:
    r = float(input("원의 반지름을 입력하세요 >> "))
    if r < 1:
        print("프로그램을 종료합니다.")
        print("컴퓨터공학과_20170677_오융택")
        break
    print("반 지름이 {}인 원의 넓이는 {:.1f}이고, \n둘레의 길이는 {:.1f}입니다.".format(r, circle_area(r), circle_length(r)))
