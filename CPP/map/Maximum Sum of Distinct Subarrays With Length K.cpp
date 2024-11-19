class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //-----------TLE-------------
        /*long long ans=0;
        for(int i=0;i<=nums.size()-k;i++){
            unordered_map<int,int>mp;
            long long sum = 0;
            bool isValid = true;
            for(int j=i;j<i+k;j++){
                if(mp[nums[j]]>0){
                    isValid  = false;
                    break;
                }
                mp[nums[j]]++; 
                sum += nums[j]; 
            }
            if (isValid)
                ans=max(sum,ans);
        }
        return ans;*/
        
        long long ans =0;
        long long sum =0;
        unordered_map<int, int>mp;

        int n = nums.size();
        int left =0;
        for (int right =0;right<n;right++){
            mp[nums[right]]++;
            sum+=nums[right];

            //if the window size exceed k, shrink the window
            while (right-left+1>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                sum-=nums[left];
                left++;
            }
            if(right-left+1==k && mp.size()==k){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
