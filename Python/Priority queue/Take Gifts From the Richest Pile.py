class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq=[]
        for i in gifts:
            heapq.heappush(pq, -i)
        
        while k!=0:
            k -=1
            t = -heapq.heappop(pq)
            heapq.heappush(pq,-math.floor(math.sqrt(t)))
        sum =0
        while pq:
            sum+=-heapq.heappop(pq)
        return sum
