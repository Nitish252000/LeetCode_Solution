class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n=len(nums)
        temp=[]

        temp.append(nums)

        for i in range(n-1):
            curr=[]
            for j in range(len(temp[i])-1):
                curr.append((temp[i][j]+temp[i][j+1])%10)
            temp.append(curr)
        
        return temp[n-1][0]

        
