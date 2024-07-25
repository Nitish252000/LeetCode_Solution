class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            maxsum=max(nums[i],maxsum+nums[i]);
            maxi=max(maxsum,maxi);
        }
        int minsum=nums[0];
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            minsum=min(nums[i],minsum+nums[i]);
            mini=min(minsum,mini);
        }
        return max(maxi,abs(mini));
    }
};
