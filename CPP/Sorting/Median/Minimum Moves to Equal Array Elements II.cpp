class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = n / 2;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < median) {
                ans += nums[median] - nums[i];
            } else if (i > median) {
                ans += nums[i] - nums[median];
            }
        }
        return ans;
    }
};
