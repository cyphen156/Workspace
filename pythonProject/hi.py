from konlpy.tag import Kkma

Kkma = Kkma()
text = "아버지가 방에 들어갑니다."

morphs = Kkma.morphs(text)
print(morphs)