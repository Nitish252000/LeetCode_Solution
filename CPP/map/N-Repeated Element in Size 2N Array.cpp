class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int sz=nums.size();
        int n =sz/2;
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }
        for(auto i:mp){
            if(i.second==n){
                return i.first;
            }
        }
        return 0;
    }
};
