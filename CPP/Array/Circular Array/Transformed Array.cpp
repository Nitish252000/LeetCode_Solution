class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int j = (i + nums[i]) % n;
                ans.push_back(nums[j]);
            } else if (nums[i] < 0) {
                int j = (i + nums[i]) % n;
                if (j < 0)
                    j += n;
                ans.push_back(nums[j]);
            } else
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
