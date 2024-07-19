class Solution {
public:
    int helper(vector<int>&nums, int index, int target, vector<int>&dp){
        if(index==nums.size()-1)return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = INT_MIN;
        for(int i=index+1;i<nums.size();i++){
            if(abs(nums[i]-nums[index])<=target){
                ans=max(ans,1+helper(nums,i,target,dp));
            }
        }
        dp[index]=ans;
        return dp[index];
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1);
        int ans = helper(nums,0,target,dp);
        if(ans>0)return ans;
        return -1;
    }
};
