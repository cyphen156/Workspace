import random as rnd

guess_num = rnd.randint(1, 100)
a = 0
print("숫자를 맞춰 보세요. (1~100)\n 맞출때까지 안끝납니다.")
while True:
    a = int(input())
    if 0 >= a or a >= 100:
        print("숫자가 이상합니다")
        continue
    if a == guess_num:
        print("맞췃습니다")
        break
    elif a > guess_num:
        print("더 작은 숫자입니다")
    else :
        print("더 큰 숫자입니다.")