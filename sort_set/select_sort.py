def select_sort(lst):
    for i in range(len(lst)):
        for j in range(len(lst)-i):
            if lst[i]>lst[i+j]:
                lst[i],lst[i+j] = lst[j+i],lst[i]
    return lst

print(select_sort([1,3,2,9,5,4,39,22,27]))