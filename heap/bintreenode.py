class bintreenode():
    def __init__(self,data,left=None,right=None):
        self.data,self.left,self.right = data,left,right
class bintree():
    def __init__(self,root):
        self.root = root
    def preorder_trav(self,root):
        if not root:
            return []
        return [root.val] + self.preorder_trav(root.left) + self.preorder_trav(root.right)

