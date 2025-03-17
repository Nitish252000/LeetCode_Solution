class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        thisdict={}
        for num in nums:
            thisdict[num]=thisdict.get(num,0)+1
        for i in thisdict:
            if thisdict[i]%2==1:
                return False
        return True
