class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // int total = 0;
        // for (auto num : nums) {
        //     total += num;
        // }
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1)
            return false;
        int target = total/2;
        // bottom -up approach (Iterative - approach)
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];  // Either we take it or we don't
            }
        }
        return dp[target];
    }
};
