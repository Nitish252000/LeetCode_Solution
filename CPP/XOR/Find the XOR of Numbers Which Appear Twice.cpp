int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int ans = 0;
        for(auto i:mp){
            if(i.second==2)ans=ans^i.first;
        }
        return ans;
}
