class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        int npair=0;
        int leftover=0;
        for(auto i:mp){
            if(i.second%2==0){
                npair+=i.second/2;
            }
            else{
                //leftover+=1;
                leftover+=i.second%2;
                npair+=i.second/2;
            }
        }
        return {npair,leftover};
    }
};
