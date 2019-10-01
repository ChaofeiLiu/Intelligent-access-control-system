from collections import deque
class stack():
    def __init__(self):
        self.list = deque()
    def append(self,val):
        return self.list.append(val)
    def pop(self):
        return self.list.pop()
    def ematy(self):
        return len(self.list) == 0
def test_stack():
    s = stack()
    s.append(1)
    s.append(2)
    s.append(3)
    print(s.pop())
    print(s.pop())
    print(s.pop())
test_stack()