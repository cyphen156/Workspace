"""
def insertion_sort2(A, n):
    for i in range(n-1):
        j = i-1
        while j >= 0 and A[j] > A[j+1]:
            A[j], A[j+1] = A[j+1], A[j]
            j = j-1

A = ['a', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm']
result = insertion_sort2(A, 2)
print(result)
A = [1, 2, 3, 4, 5, 6, 7]

def reverse(A, i):
    while i != len(A):
        i += 1
        reverse(A, i)
        print(A[i-1])
        break

reverse(A, 0)

def insertion_sort(c):
    for i in range(len(c)):
        key = c[i]
        j = i-1
        while j >= 0 and c[j] > key:
            c[j+1] = c[j]
            j -= 1
        c[j+1] = key

c = [1, 8, 4, 6, 3, 2]
insertion_sort(c)
print(c)

def quick_sort(arr):
    def sort(low, high):
        if high <= low:
            return

        mid = partition(low, high)
        sort(low, mid - 1)
        sort(mid, high)

    def partition(low, high):
        pivot = arr[(low + high) // 2]
        while low <= high:
            while arr[low] < pivot:
                low += 1
            while arr[high] > pivot:
                high -= 1
            if low <= high:
                arr[low], arr[high] = arr[high], arr[low]
                low, high = low + 1, high - 1
        return low

    return sort(0, len(arr) - 1)
B = [3, 5, 7, 9, 1, 2, 4, 6, 8]
quick_sort(B)
print(B)
"""
from random import random


A = [1, 2, 3, 4, 5, 6, 8, 9, 10]
for i in range(len(A)):
    if A[i] != i+1:
        break
    else:
        print(A[i])

