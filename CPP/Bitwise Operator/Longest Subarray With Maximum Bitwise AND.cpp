class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr_streak = 0;
        int ans = 0;
        int max_value=*max_element(nums.begin(),nums.end());      
        for(auto num:nums){
            if(num==max_value){
                curr_streak++;
                ans=max(ans,curr_streak);
            }
            else{
                curr_streak=0;
            }
        }
        return ans;
    }
};
