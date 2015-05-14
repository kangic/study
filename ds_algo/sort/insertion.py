# -*- coding: utf-8 -*-

def insertion_sort(ar):
    for i in range(1, len(ar)):
        idx = i - 1
        value = ar[i]
        while (idx >= 0 and ar[idx] > value):
            ar[idx + 1] = ar[idx]
            idx = idx - 1
        ar[idx + 1] = value
    return ar

if __name__ == "__main__":
    changed_ar = insertion_sort([3,6,1,8,5,9,4,2,7])
    print(changed_ar)
