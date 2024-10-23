# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        levelsum=[]
        q=[]
        q.append(root)
        #1st: bfs
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
            levelsum.append(sum)
        #2nd:bfs
        q2=[]
        q2.append(root)
        level =1
        root.val=0
        while len(q2) !=0:
            s=len(q2)
            for i in range(s):
                curr=q2.pop(0)
                siblingsum = 0
                if curr.left:
                    siblingsum+=curr.left.val
                if curr.right:
                    siblingsum+=curr.right.val
                if curr.left:
                    curr.left.val=levelsum[level]-siblingsum
                    q2.append(curr.left)
                if curr.right:
                    curr.right.val=levelsum[level]-siblingsum
                    q2.append(curr.right)
            level+=1
        return root
        
