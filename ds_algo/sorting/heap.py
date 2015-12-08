# -*- coding: utf-8 -*-

# heap -> essentially complete binary tree
def heapify(ar, idx, max_idx):
    left = 2 * idx + 1
    right = 2 * idx + 2

    largest = idx

    if (left < max_idx) and (ar[left] > ar[idx]):
        largest = left

    if (right < max_idx) and (ar[right] > ar[largest]):
        largest = right

    if largest != idx:
        ar[idx], ar[largest] = ar[largest], ar[idx]
        heapify(ar, largest, max_idx)

def build_heap(ar):
    for i in range(len(ar) / 2 - 1, -1, -1): # include index 0
        heapify(ar, i, len(ar) - 1)

def heap_sort(ar):
    build_heap(ar)
    for i in range(len(ar) - 1, 0, -1):
        ar[0], ar[i] = ar[i], ar[0]
        heapify(ar, 0, i)

    return ar

if __name__ == "__main__":
    changed_ar = heap_sort([3,6,1,8,5,9,4,2,7])
    print(changed_ar)
