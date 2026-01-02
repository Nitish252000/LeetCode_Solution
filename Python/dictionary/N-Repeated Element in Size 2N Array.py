class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        sz = len(nums)
        n = sz // 2
        thisdict = {}

        for num in nums:
            thisdict[num] = thisdict.get(num, 0) + 1
        

        for k,v in thisdict.items():
            if v == n:
                return k
        return 0
