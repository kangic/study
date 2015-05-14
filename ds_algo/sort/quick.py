# -*- coding: utf-8 -*-

def quick_sort(ar, left, right):
    if left < right:
        pi = partition(ar, left, right)
        quick_sort(ar, left, pi - 1)
        quick_sort(ar, pi + 1, right)
    return ar
        
def partition(ar, left, right, minimum_cnt):
    p = (left + right) / 2 # select a pivot index from {left, mid, right}
    ar[p], ar[right] = ar[right], ar[p] # swap
    store = left
    for i in range(left, right):
        if ar[i] <= ar[right]:
            ar[i], ar[store] = ar[store], ar[i] # swap
            store = store + 1
    ar[store], ar[right] = ar[right], ar[store] # swap
    return store

if __name__ == "__main__":
    changed_ar = quick_sort([3,6,1,8,5,9,4,2,7], 0, 8, 5)
    print(changed_ar)
