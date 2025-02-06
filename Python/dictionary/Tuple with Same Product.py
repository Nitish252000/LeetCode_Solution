class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        cnt=0
        this_dict={}
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                product=nums[i]*nums[j]
                cnt+=this_dict.get(product,0)*8
                this_dict[product]=this_dict.get(product,0)+1
        return cnt
