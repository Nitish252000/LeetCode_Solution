class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        // -------- Method 1 : T.C = O(nlog(n)) ----------
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n - 1] + nums[n - 2] - nums[0];

        // ------------- Method 2: T.c = O(N) ----------

        int smallest = INT_MAX;
        int largest = INT_MIN;
        int second_largest = INT_MIN;

        for (auto num : nums) {
            if (num < smallest)
                smallest = num;

            if (num > largest) {
                second_largest = largest;
                largest = num;
            } else if (num > second_largest) {
                second_largest = num;
            }
        }
        return largest + second_largest - smallest;
    }
};
