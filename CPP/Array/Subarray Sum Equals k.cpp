int subarraySum(vector<int>& nums, int k) {
       /* int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k)
                ans++;
            int sum = 0;
            sum = sum + nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                sum = sum + nums[j];
                if (sum == k)
                    ans++;
            }
        }
        return ans;*/

        //??Optimised
        int sum=0,cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum==k)cnt++;
            if(mp.find(sum-k)!=mp.end())cnt=cnt+mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
