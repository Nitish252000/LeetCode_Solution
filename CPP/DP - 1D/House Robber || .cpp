int solve(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];

        if (dp[n] != -1)
            return dp[n];

        int incl = solve(nums, n - 2, dp) + nums[n];
        int excl = solve(nums, n - 1, dp) + 0;

        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>first, second;

        for(int i=0; i<n; i++){
            if(i != n-1)first.push_back(nums[i]);
            if(i != 0)second.push_back(nums[i]);
        }
        int m = first.size();
        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);
        return max(solve(first, m-1, dp1), solve(second, m-1, dp2));
    }
