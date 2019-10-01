def dobble_sort(lst):
    _len = len(lst)
    for i in range(_len):
        for j in range(1,_len-i):
            if lst[j-1] > lst[j]:
                lst[j-1],lst[j] = lst[j],lst[j-1]
    return lst

print(dobble_sort([89,1,2,5,3,9,8,11,7]))


