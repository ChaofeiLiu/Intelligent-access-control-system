def quick_sort(lst):
    if len(lst) <2 :
        return  lst
    else:
        mid = lst[0]
        left = [i for i in lst[1:] if i<mid]
        right = [i for i in lst[1:] if i>=mid]
    return quick_sort(left) + [mid] +quick_sort(right)

print(quick_sort([1,4,2,9,5,3,6]))
