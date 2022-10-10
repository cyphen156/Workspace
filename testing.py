"""
min_distance(A)
    // 입력: 숫자배열 A[o..n-1]
    // 출력: 두 항목간의 거리들 중의 최소 거리
    dmin <- ~
        for i <- 0 to n-1 do
            for j <- n-1 to i+1 do //for j <- i+1 to n-1 do
                if i != j and |A[i] - A[j]| < dmin
                    dmin <- |A[i] - A[j]|
    return dmin

/*
j의 인덱스를 i부터 시작하면 (0, 0), (1, 0), (1, 1)과 같이 이미 계산을 한 두 항목의 
거리를 다시 계산하게 되므로 j의 인덱스를 i+1부터 계산하거나 역순으로 n-1부터 i+1까지만 계산하도록 진행시킨다.
*/
A = [3, 7, 9, 4, 2, 8, 1, 5]
n = len(A)
def selection_sort(A, n):
    for i in range(n-2):
        least = i
        for j in range(n-1):
            if A[j] < A[least]:
                least = j
        (A[i], A[least]) = (A[least], A[i])

selection_sort(A, n)
print("after selection_sorting(A) : ")
print(A)

inserting_sort(arr, ins)
    for i <- 1 to len(arr) do
    temp = arr[i];
    j = i-1;
        while j >= 0 and temp < arr[j]:
            arr[j+1] <- arr[j];
            j = <- j-1;
        arr[j+1] <- temp;
def inserting_sort(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i-1
        while j >= 0 and temp < arr[j]:
            arr[j+1] = arr[j]
            j = j-1
        arr[j+1] = temp

arr = [3, 7, 9, 4, 2, 8, 1, 5]
inserting_sort(arr)
list2 = []
print("after insertingsort")
for i in range(len(arr)):
    list2.append(arr[i])
print(list2)


list = []

def pushlist():
    while True:
        list.append(input())
        print(list)
        if list[-1] == '':
            list.pop()
            break


pushlist()


def printlist(list):
    for i in range(len(list)):
        print(list.pop())


printlist(list)
result = 0
for i in range(1, 4097):
    if i % 2 == 0:
        print("+{}", i)
        result += i
print(result)
"""
