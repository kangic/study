# -*- coding: utf-8 -*-

def selection_sort(ar):
    for i in range(0, len(ar)):
        min_idx = i;
        for j in range(i, len(ar)):
            if ar[j] < ar[min_idx]:
                min_idx = j
        ar[i], ar[min_idx] = ar[min_idx], ar[i]
    return ar

if __name__ == "__main__":
    changed_ar = selection_sort([3,6,1,8,5,9,4,2,7])
    print(changed_ar)
