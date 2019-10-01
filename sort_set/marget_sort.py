def merge(left,right):
    result = []
    while left and right:
        result.append(left.pop(0) if left[0] <= right[0] else right.pop(0))
    while left:
        result.append(left.pop(0))
    while right:
        result.append(right.pop(0))

    return result

def merge_sort(lst):
    if len(lst)<=1:
        return lst
    mid_index = int(len(lst)/2)
    left = merge_sort(lst[:mid_index])
    right = merge_sort(lst[mid_index:])
    return merge(left,right)

print(merge_sort([0.1,12,6723,2212,9,2,5,1,7,8,20,2,1]))
