# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        result = []
        cur_node = [root]
        next_node = []
        result.append([i.val for i in cur_node])
        while cur_node or next_node:
            for node in cur_node:
                if node.left:
                    next_node.append(node.left)
                if node.right:
                    next_node.append(node.right)
            if next_node:
                result.append([i.val for i in next_node])
            cur_node = next_node
            next_node = []
        return result