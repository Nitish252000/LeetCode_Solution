**Intuition Behind Kadane’s Algorithm**

Kadane’s algorithm is an optimized approach to find the maximum subarray sum in O(n) time complexity, avoiding the brute-force O(n²) or O(n³) solutions.

**1. Key Idea: Expand or Restart?**

As we iterate through the array, we make a decision at each step:

Should we extend the current subarray? (Adding num to the ongoing sum)
Or should we start a new subarray? (Resetting the sum to num)
This decision is made based on whether adding the new number increases or decreases the sum.

**2. Kadane's Algorithm in Action**
We maintain:

cur_max → Tracks the maximum subarray sum ending at the current element.
max_sum → Stores the overall maximum subarray sum found so far.
Algorithm Steps:
Start with cur_max = 0 and max_sum = 0 (or INT_MIN for negative numbers).
Iterate through the array:
Update cur_max = max(num, cur_max + num).
Update max_sum = max(max_sum, cur_max).
Return max_sum.
