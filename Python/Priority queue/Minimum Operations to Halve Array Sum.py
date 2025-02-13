class Solution:
    def halveArray(self, nums: List[int]) -> int:
        pq=[]
        sum=0.0
        for num in nums:
            heapq.heappush(pq,-num)
            sum+=num    
        curr_sum=sum
        half=sum/2.0   # // performs integer division, which is incorrect for floating-point calculations.Fix: Use half = sum / 2.0 instead.
        total_oper=0
        while curr_sum>half:
            x=-heappop(pq)
            reduced=x/2.0
            heappush(pq,-reduced)
            curr_sum-=reduced
            total_oper+=1
        return total_oper
