# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:
   
    def __init__(self, root: Optional[TreeNode]):
        self.seen=set()
        self.bfs(root)
        

    def find(self, target: int) -> bool:
        if target in self.seen:
            return True
        return False

    def bfs(self, root: Optional[TreeNode]):
        root.val=0
        q=[]
        q.append(root)
        while q:
            front=q.pop(0)
            self.seen.add(front.val)
            if front.left:
                front.left.val=2*front.val+1
                q.append(front.left)
            if front.right:
                front.right.val=2*front.val+2
                q.append(front.right)
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
