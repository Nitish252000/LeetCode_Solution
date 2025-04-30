class Solution:
    def check(self, num: int) -> bool:
        cnt = 0
        while num != 0:
            cnt += 1
            num //= 10
        if cnt % 2 == 0:
            return True
        return False

    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for num in nums:
            if self.check(num):
                cnt += 1
        return cnt
