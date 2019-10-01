import timeit

def insert_sort1(arr):
    for i in range(len(arr)):
        for j in range(i,0,-1):
            if arr[j] < arr[j-1]:
                arr[j-1] = arr[j]
    return  arr

def insert_sort2(arr, n):
    for i in range(1, n):
        current_value = arr[i]
        for j in range(i, 0, -1):
            if current_value < arr[j - 1]:
                arr[j] = arr[j - 1]
            else:
                arr[j] = current_value
                break
    return arr


# print(insert_sort([1,23,4,2,6,9,7,8,88,67],10))
if __name__ == '__main__':
    t = timeit.Timer('insert_sort2([1,23,4,2,6,9,7,8,88,67],10)','from __main__ import insert_sort2')
    t1 = timeit.Timer('insert_sort1([1,23,4,2,6,9,7,8,88,67])','from __main__ import insert_sort1')
    print(t.timeit(number=100000))
    print(t1.timeit(number=100000))
