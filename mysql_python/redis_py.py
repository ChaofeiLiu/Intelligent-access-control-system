import redis

class TestString():
    def __init__(self):
        self.r = redis.StrictRedis(host='127.0.0.1',port=6379,db=0)

    def test_set(self,k,v):
        rs = self.r.set(k,v)
        if rs:
            print(rs)
        else:
            return False

    def test_get(self,key):
        rs = self.r.get(key)
        if rs:
            print(rs)
            return rs
        else:
            return 'Not exist'

    def  test_mset(self):
        d = {
            'user3':'Bob',
            'user4':'Tom'
        }
        rs =self.r.mset(d)
        if rs:
            print(rs)
        else:
            return False

    def test_mget(self):
        l = ['user1','user3','user2']
        rs = self.r.mget(l)
        if rs:
            print(rs)
            return rs
        else:
            return 'Not exist'

    def test_append(self):
        rs =self.r.append('user5','Jenny')
        if rs:
            print(rs)
        else:
            return False

    def test_delete(self,key):
        rs = self.r.delete(key)
        if rs:
            print(rs)
        else:
            return False
class TestList():
    def __init__(self):
        self.r = redis.StrictRedis(host='localhost',port=6379, db=0)

    def test_push(self,key,*t):
        '''lpush/rpush 从最左或最右边加入元素'''
        self.r.lpush(key,*t)
        rs = self.r.lrange(key,0,-1)
        if rs:
            print(rs)
        else:
            return False

    def test_pop(self,key):
        '''lpop/rpop 从最左最右移除元素'''
        self.r.lpop(key)
        rs = self.r.lrange(key,0,-1)
        if rs:
            print(rs)
        else:
            return False

    def test_pushx(self,key,value):
        '''lpushx/rpushx  从列表最左边或最右边加入一个值'''
        self.r.rpushx(key,value)
        rs = self.r.lrange(key,0,-1)
        if rs:
            print(rs)
        else:
            return False

    def test_trim(self,key):
        '''ltrim/rtrim(key,start,end)  从左边或右边截取一定长度的值截取'''
        self.r.ltrim(key,0,1)
        rs =self.r.lrange(key,0,-1)
        if rs:
            print(rs)
        else:
            return False

class TestSet():
    def __init__(self):
        self.r = redis.StrictRedis(host='localhost',port=6379,db=0)

    def s_add(self,key,*value):
        self.r.sadd(key,*value)
        rs = self.r.smembers(key)
        if rs:
            print(rs)
        else:
            return False

    def s_rem(self,key,*values):
        self.r.srem(key,*values)
        rs = self.r.smembers(key)
        if rs:
            print(rs)
        else:
            return False

    def s_inter(self,*set):
        rs = self.r.sinter(*set)
        print(rs)

    def s_union(self,*set):
        rs = self.r.sunion(*set)
        print(rs)

    def s_diff(self,*set):
        rs = self.r.sdiff(*set)
        print(rs)

class TestHash():
    def __init__(self):
        self.r = redis.StrictRedis(host='localhost',port=6379,db=0,charset='utf8')

    def h_set(self,name,key,val):
        self.r.hset(name,key,val)
        rs = self.r.hget(name,key)
        print(rs)

    def h_mset(self,name,mapping,keys):
        self.r.hmset(name,mapping)
        rs = self.r.hmget(name,keys)
        print([str(i, encoding='utf-8') for i in rs])






def main():
    # k = 'user6'
    # v = 'Rose'
    # key = 'user5'
    # str_obj = TestString()
    # str_obj.test_get(key)
    '''
    key = 'ltest3'
    value = 'snake'
    t = ['dog','cat','cow','snake']
    list_obj = TestList()
    list_obj.test_trim(key)

    set = ['zoo3','zoo2','zoo1']
    key = 'zoo3'
    values = ['dog','cow','cat','turtle','fish','snake']
    values1 = ['dag','cow']
    values2 = ['bee','shape','pig']
    s_obj = TestSet()
    s_obj.s_diff(*set)
    '''
    name ='省会'
    mapping = {'福建':'福州','云南':'昆明','辽宁':'沈阳'}
    # h_obj = TestHash()
    # h_obj.h_set(name,'shanxi','xian')

    h_obj = TestHash()
    h_obj.h_mset(name,{'Beijing':'beijing'},'Beijing')
    h_obj.h_mset(name,mapping,['福建','云南','辽宁'])

main()
