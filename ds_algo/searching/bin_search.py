def recursive_bin_search(arr, left, right, t):
    if left > right:
        return -1

    p = (left + right) / 2
    if t == arr[p]:
        return p
    elif t > arr[p]:
        return recursive_bin_search(arr, p+1, right, t)
    else:
        return recursive_bin_search(arr, left, p-1, t)

def iterative_bin_search(arr, left, right, t):
    l = left
    r = right
    while True:
        if l > r:
            return -1

        p = (l + r) / 2
        if t == arr[p]:
            return p
        elif t > arr[p]:
            l = p + 1
        else:
            r = p - 1

if __name__ == '__main__':
    ar = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]

    print recursive_bin_search(ar, 0, 19, 8)
    print recursive_bin_search(ar, 0, 19, 25)

    print iterative_bin_search(ar, 0, 19, 8)
    print iterative_bin_search(ar, 0, 19, 25)


