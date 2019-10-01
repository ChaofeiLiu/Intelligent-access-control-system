import heapq
class mink():
    def __init__(self,iterable,k):
        self.max_heap = []
        self.want_k = k
        self.iterable = iterable
    #初始化最小堆，分别有两个属性，iterable为可迭代内容，k为最大数的个数
    def push(self,val):
        if len(self.max_heap) >= self.want_k:
            #如果min_heap长度大于k，则需要通过比较把大数放在min_heap中；否则直接把val放入min_heap
            max_val = self.max_heap[0]
            if val > max_val:
                pass
            else:
                heapq.heapreplace(self.max_heap,val)
                #如果val大于min_val那么让val代替 min_val
        else:
            heapq.heappush(self.max_heap,val)
    def get_topk(self):
        for val in self.iterable:  #遍历可迭代对象 iterable
            self.push(val)
        return self.max_heap
def test():
    import random
    i = list(range(1000))
    random.shuffle(i)
    _ = mink(i,10)
    print(_.get_topk())
test()