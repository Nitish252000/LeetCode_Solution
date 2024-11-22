class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt =0;
        for(auto i:nums){
            int find = k-i;
            if(mp[find]>0){
                mp[find]--;
                cnt++;
            }
            else
                mp[i]++;
        }
        return cnt;        
    }
};
