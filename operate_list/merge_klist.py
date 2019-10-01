from heapq import heapify,heappop
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        #读取链表值
        h = []
        for node in lists:
            while node:
                h.append(node.val)
                node = node.next
        #构造最小堆
        if not h:
            return h == None
        heapify(h)
        #构造链表存储堆弹出的值
        root = ListNode(heappop(h))
        curnode = root
        while h:
            nodenext = ListNode(heappop(h))
            curnode.next = nodenext
            curnode = nodenext
        return root
