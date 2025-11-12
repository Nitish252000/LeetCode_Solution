class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = 0;
        int num1 = 0;
        for (auto num : nums) {
            if (num == 1)
                num1++;
            g = gcd(g, num);
        }
        if (num1 > 0) {
            return nums.size() - num1;
        }
        if (g > 1) {
            return -1;
        }
        int minL = INT_MAX;
        // Find the shortest subarray with gcd == 1
        for (int i = 0; i < nums.size(); i++) {
            int curr_gcd = nums[i];
            for (int j = i; j < nums.size(); j++) {
                curr_gcd = gcd(curr_gcd, nums[j]);
                if (curr_gcd == 1) {
                    minL = min(minL, j - i + 1);
                    break; // Shortest subarray with gcd==1, starting from index
                           // i
                }
            }
        }
        return minL - 1 + n - 1;
    }
};
