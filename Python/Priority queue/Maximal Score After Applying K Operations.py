class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        # Use -i while pushing elements into the heap to simulate a max-heap using heapq (since heapq is a min-heap by default).
        score = 0
        pq = []
        for i in nums:
            heapq.heappush(pq, -i)
        while k > 0:
            k -= 1
            # Get the largest element by popping the smallest negative value
            maxele = -heapq.heappop(pq)
            score += maxele
            # Push the new value (ceiling of maxele/3) back into the heap as negative
            heapq.heappush(pq, -math.ceil(maxele / 3))
        return score
