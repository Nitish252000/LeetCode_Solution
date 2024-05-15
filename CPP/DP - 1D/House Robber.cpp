//Recursion + memoization 

int solve(vector<int>& nums, int n, vector<int> &dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];

        if (dp[n] != -1)
            return dp[n];
  
        //step 3: check in dp array
        int incl = solve(nums, n - 2, dp) + nums[n];
        int excl = solve(nums, n - 1, dp) + 0;
  
        //step 2: store the sub-problem  value
        dp[n] = max(incl, excl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //step 1: Create and initialize dp array
        vector<int> dp(n, -1);   
        return solve(nums, n - 1, dp); // start solving from last house
    }
