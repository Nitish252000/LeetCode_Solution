class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        st = set(nums)
        target = original
        while target in st:
            target *= 2
        return target
