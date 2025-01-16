class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        l1=len(nums1)
        l2=len(nums2)
        fq={}
        for num in nums1:
            fq[num]=fq.get(num,0)+l2
        for num in nums2:
            fq[num]=fq.get(num,0)+l1
        ans =0
        for num in fq:
            if fq[num]%2==1:
                ans^=num
        return ans

        
