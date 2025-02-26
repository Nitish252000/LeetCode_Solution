class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //*-------Brute force approach O(n2)------------
        /*int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum+=nums[j];
                maxi=max(abs(sum),maxi);
            }
        }
        return maxi;*/

        //--------Kadens Algorithm-----
        int maxi = nums[0];
        int sum1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum1 = max(nums[i], sum1 + nums[i]);
            maxi = max(maxi, sum1);
        }

        int mini = nums[0];
        int sum2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum2 = min(sum2 + nums[i], nums[i]);
            mini = min(mini, sum2);
        }
        return max(maxi, abs(mini));
        /*
        1. Key Idea: Expand or Restart?
            As we iterate through the array, we make a decision at each step:
                Should we extend the current subarray? (Adding num to the ongoing sum)
                Or should we start a new subarray? (Resetting the sum to num)
            This decision is made based on whether adding the new number increases or decreases the sum.

        2. Kadane's Algorithm in Action
            We maintain:
                cur_max → Tracks the maximum subarray sum ending at the current element.
                max_sum → Stores the overall maximum subarray sum found so far.
            Algorithm Steps:
                Start with cur_max = 0 and max_sum = 0 (or INT_MIN for negative numbers).
                Iterate through the array:
                    Update cur_max = max(num, cur_max + num).
                    Update max_sum = max(max_sum, cur_max).
                    Return max_sum.
        */
    }
};
