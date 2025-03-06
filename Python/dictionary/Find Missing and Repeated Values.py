class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        thisdict={}

        n=len(grid)

        for i in range(n):
            for j in range(len(grid[0])):
                thisdict[grid[i][j]]=thisdict.get(grid[i][j],0)+1
        
        missing =-1
        repeating=-1

        for i in range(1,n*n+1):
            if i not in thisdict:
                missing = i
            elif thisdict[i]>1:
                repeating=i
        return [repeating,missing]
        
