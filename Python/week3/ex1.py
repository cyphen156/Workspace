##list == [] 자료의 저장 순서를 인덱싱
listA = ['mango', 'banana', 'apple', 'orange', 'kiwi']
print(listA[1])
print(listA[0])
print(listA[1:])
print(listA[:3])
print(listA[1:4:2])
print(listA[::-1])
##

print(listA[1])
print(listA[:2])
print(listA[1::3])
print(listA[-2:-5:-1])
#== reverse
print(listA.reverse())
print(listA)

color1 = ['red', 'blue', 'green']
color2 = ['orange', 'black', 'white']
color3 = []
##for i in 3:
#    color3[i] = color1[i] + color2[i]
#    print(color3[i])
print(color3)
print(color1+color2)
print(len(color1+color2))
total = color1+color2
print(total)
print(len(total))
print(color1*2)

print('blue' in color2)

color1.append("white")
print(color1)
color1.pop()
print(color1)
color1.remove('red')
print(color1)
color1.extend(color2)
print(color1)
color1.insert(0, 'yellow')
print(color1)
del color1[4]
print(color1)
## slicing == list[start:end] if [:] === first to end,
# [-first:-end] == reverse -1, -2, -3 .... !!! -0가 없는 이유 --> 2진 보수
# cities[::2] === 2는 건너뛰는 갯수 == 증가값 -> 0, 2, 4, 6 ....



# init = (String)input()
# array = []
# i = 0;
# while True:
#     array[i] = init[i]
#     print(array[i])
#     i += 1


kor = [49, 79, 20, 100, 80]
math = [43, 59, 85, 30, 90]
eng = [49, 79, 48, 60, 100]
midterm_score = [kor, math, eng]

print(midterm_score)
idx = ['a', 'b', 'c', 'd', 'e']
for i in range(len(kor)):
    sum = kor[i] + math[i] + eng[i]
    evg = sum/len(midterm_score)
    print("{}학생의 합계 점수는 {}, 평균은 {}입니다.".format(idx[i], sum, evg))