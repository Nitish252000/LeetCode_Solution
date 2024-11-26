class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indegree=[0]*n
        for i in edges:
            indegree[i[1]]+=1
        chmpcnt=0
        chmp=-1
        for i in range(len(indegree)):
            if indegree[i]==0:
                chmpcnt+=1
                chmp=i
        if chmpcnt>1:
            return -1
        else:
            return chmp

      
