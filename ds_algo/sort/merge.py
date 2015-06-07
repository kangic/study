# -*- coding: utf-8 -*-

def merge_sort(ar, left, right):
    if left < right:
        mid = (left + right) / 2
        merge_sort(ar, left, mid)
        merge_sort(ar, mid + 1, right)
        merge(ar, left, mid, right)

    return ar

def merge(ar, left, mid, right):
    b1 = left
    b2 = mid + 1
    e1 = mid
    e2 = right

    sorted = []

    while (b1 <= e1 and b2 <= e2):
        if ar[b1] < ar[b2]:
            sorted.append(ar[b1])
            b1 = b1 + 1
        else:
            sorted.append(ar[b2])
            b2 = b2 + 1

    while b1 <= e1:
        sorted.append(ar[b1])
        b1 = b1 + 1

    while b2 <= e2:
        sorted.append(ar[b2])
        b2 = b2 + 1

    idx = left
    for i in range(len(sorted)):
        ar[idx] = sorted[i]
        idx = idx + 1

if __name__ == "__main__":
    print(merge_sort([5, 2, 4, 9], 0, 3))
    print(merge_sort([3,6,1,8,5,9,4,2,7], 0, 8))
