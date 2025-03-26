class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        thislist=[]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                thislist.append(grid[i][j])

        thislist.sort()
        base= thislist[0]
        for i in range(len(thislist)):
            if abs(base-thislist[i])%x!=0:
                return -1
        mid=thislist[len(thislist)//2]
        oper=0
        for i in thislist:
            oper+=abs(mid-i)//x
        return oper



        
