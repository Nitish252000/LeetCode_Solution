# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        pq=[]
        q=[]
        q.append(root)
        level =1
        while len(q) !=0:
            size=len(q)
            sum=0
            for i in range(size):
                ele=q.pop(0)
                sum+=ele.val
                if ele.left:
                    q.append(ele.left)
                if ele.right:
                    q.append(ele.right)
            heapq.heappush(pq,(-sum,level))
            level+=1
        s,l=heapq.heappop(pq)
        return l 
