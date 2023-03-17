age = 2023 - int(input("당신이 태어난 연도를 입력하세요."))

if 27 > age > 7:
    if age >= 20:
        print("대학생")
    elif age >= 17:
        print("고등학생")
    elif age >=14:
        print("중학생")
    elif age >= 8:
        print("초등학생")
else:
    print("학생이 아닙니다.")
