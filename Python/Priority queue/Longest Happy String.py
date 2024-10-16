class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        if a > 0:
            heapq.heappush(pq, (-a, "a"))
        if b > 0:
            heapq.heappush(pq, (-b, "b"))
        if c > 0:
            heapq.heappush(pq, (-c, "c"))
        ans = ""
        while len(pq) > 0:
            cnt1, ch1 = heapq.heappop(pq)
            cnt1 = -cnt1
            if len(ans) >= 2 and ans[len(ans) - 1] == ch1 and ans[len(ans) - 2] == ch1:
                if not pq:
                    break
                cnt2, ch2 = heapq.heappop(pq)
                cnt2 = -cnt2
                ans += ch2
                if cnt2 - 1 > 0:
                    heapq.heappush(pq, (-(cnt2-1), ch2))
            else:
                cnt1 -= 1
                ans += ch1
            if cnt1 > 0:
                heapq.heappush(pq, (-cnt1, ch1))
        return ans
