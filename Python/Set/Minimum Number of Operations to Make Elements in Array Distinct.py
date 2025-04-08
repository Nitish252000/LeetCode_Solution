class Solution:
    def check(self,nums:List[int], index:int)->bool:
        st=set()
        for i in range(index,len(nums)):
            if nums[i] in st:
                return False
            st.add(nums[i])
        return True


    def minimumOperations(self, nums: List[int]) -> int:
        ans=0
        for i in range(0,len(nums),3):
            if self.check(nums,i):
                break
            ans+=1
        return ans
