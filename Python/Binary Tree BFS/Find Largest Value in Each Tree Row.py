# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ans=[]
        q=[]
        q.append(root)
        while q:
            size=len(q)
            maxi = float('-inf')  # Initialize max value for this level
            for i in range(size):
                node = q.pop(0)
                maxi=max(maxi,node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(maxi)
        return ans
        
