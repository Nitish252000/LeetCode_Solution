class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum=nums[0]
        maxi=nums[0]
        for i in range(1,len(nums)):
            sum = max(nums[i],nums[i]+sum)
            maxi= max(maxi,sum)
        return maxi
        

Explanation

Initialization:
sum = nums[0]: This initializes the variable sum to the first element of the array. This variable keeps track of the maximum sum of the subarray ending at the current position.
maxi = nums[0]: This initializes the variable maxi to the first element of the array. This variable stores the maximum sum found so far.

Iteration:
for i in range(1, len(nums)):: This loop iterates over the array starting from the second element (index 1) to the end of the array.

Update sum:
sum = max(nums[i], nums[i] + sum): This line updates the sum. For each element in the array, it checks whether adding the current element to the existing sum is better (greater) than starting a new subarray from the current element. It assigns the maximum of these two values to sum.
    
Update maxi:
maxi = max(maxi, sum): This line updates maxi to be the maximum of the current maxi and the updated sum. This ensures that maxi always holds the highest sum of any subarray found so far.
    
Return the Result:
return maxi: Finally, the method returns maxi, which is the maximum sum of any contiguous subarray in the given list.            
