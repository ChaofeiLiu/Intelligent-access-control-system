def shell_sort(relist):
    n = len(relist)
    gap = int(n / 2 ) # 初始步长
    while gap > 0:
        for i in range(gap, n):
            temp = relist[i]  # 每个步长进行插入排序
            j = i
            # 插入排序
            while j >= gap and relist[j - gap] > temp:
                relist[j] = relist[j - gap]
                j -= gap
            relist[j] = temp

        gap = int(gap / 2 )

    return relist


print(shell_sort([1,9,4,3,7,0,2,6,11,10,23,22,29,27]))

