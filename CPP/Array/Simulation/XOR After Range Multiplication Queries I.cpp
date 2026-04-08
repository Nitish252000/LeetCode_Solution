class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1000000007;
        for (auto& q : queries) {
            int idx = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];

            while (idx <= r) {
                nums[idx] = (nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
