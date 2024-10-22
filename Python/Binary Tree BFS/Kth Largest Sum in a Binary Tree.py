# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        pq=[]
        q=[]
        
        q.append(root)
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
            heapq.heappush(pq,-sum)
        if len(pq)<k:
            return -1
        i=0
        while i <k-1:
            heapq.heappop(pq)
            i+=1
        return -heapq.heappop(pq)
