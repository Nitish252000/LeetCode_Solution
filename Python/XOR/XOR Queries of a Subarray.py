class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        ans = list()
        for i in queries:
            xorSum  = 0
            # j = i[0]
            # while j<=i[1]:
            #     xorSum=xorSum^arr[j]
            #     j+=1
            # ans.append(xorSum)
            for j in range(i[0],i[1]+1):
                xorSum=xorSum^arr[j]
            ans.append(xorSum)
        return ans
                
        
