class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        odd_cnt=0
        even_cnt=0
        sum_so_far=0
        cnt=0
        MOD=1000000007
        for num in arr:
            sum_so_far+=num
            if sum_so_far%2==0:
                cnt+=odd_cnt
                even_cnt+=1
            else:
                cnt+=even_cnt+1
                odd_cnt+=1
        return cnt%MOD
        
