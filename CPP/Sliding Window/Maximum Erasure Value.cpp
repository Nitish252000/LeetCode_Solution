class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // Method: Try to use kaden's algorithm, but it failed
        // int maxi=nums[0];
        // int sum=nums[0];
        // set<int>st;
        // for(int i=1;i<nums.size();i++){
        //     sum=max(nums[i],sum+nums[i]);
        //     maxi=max(maxi,sum);
        // }
        unordered_set<int>seen;
        int maxSum=INT_MIN;
        int currSum=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            while(seen.count(nums[right])){
                seen.erase(nums[left]);
                currSum-=nums[left];
                left++;
            }
            seen.insert(nums[right]);
            currSum+=nums[right];
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};
