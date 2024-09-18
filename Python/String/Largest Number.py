class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # li = [str(num) for num in nums]
        li = []
        for num in nums:
            li.append(str(num))
        def compare(x, y):
        # Custom comparator to decide the order
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            else:
                return 0
        li.sort(key=cmp_to_key(compare))
        if li[0]=="0":
            return "0"
        return "".join(li)
