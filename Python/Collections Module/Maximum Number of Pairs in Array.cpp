class Solution(object):
    def numberOfPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        count=Counter()
        npair =0
        leftover=0
        for num in nums:
            count[num]+=1
        for i in count:
            if count[i]%2==0:
                npair += count[i] // 2
            else:
                leftover += count[i] % 2
                npair += count[i] // 2
        return [npair,leftover]

        
