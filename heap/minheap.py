import heapq
class topk():
    def __init__(self,iterable,k):
        self.min_heap = []
        self.want_k = k
        self.iterable = iterable
    #初始化最小堆，分别有两个属性，iterable为可迭代内容，k为最大数的个数
    def push(self,val):
        if len(self.min_heap) >= self.want_k:
            #如果min_heap长度大于k，则需要通过比较把大数放在min_heap中；否则直接把val放入min_heap
            min_val = self.min_heap[0]
            if val < min_val:
                pass
            else:
                heapq.heapreplace(self.min_heap,val)
                #如果val大于min_val那么让val代替 min_val
        else:
            heapq.heappush(self.min_heap,val)
    def get_topk(self):
        for val in self.iterable:  #遍历可迭代对象 iterable
            self.push(val)
        return self.min_heap
def test():
    import random
    i = list(range(1000))
    random.shuffle(i)
    _ = topk(i,10)
    print(_.get_topk())
test()


