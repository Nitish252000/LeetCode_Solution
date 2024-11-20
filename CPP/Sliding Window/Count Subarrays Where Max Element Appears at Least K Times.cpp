class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int left=0; int maxwindowEle =0;
        long long ans =0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==maxi)maxwindowEle++;
            while(maxwindowEle==k){
                if(nums[left]==maxi)maxwindowEle--;
                left++;
            }
            ans+=left;
        }
        return ans;
    }
}
