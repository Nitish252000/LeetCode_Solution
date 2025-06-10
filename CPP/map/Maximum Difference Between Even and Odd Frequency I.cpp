class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int xodd=INT_MIN;
        int neven=INT_MAX;
        for(auto i:mp){
            if(i.second%2==1 && i.second>xodd)xodd=i.second;
            else if(i.second%2==0 && i.second<neven)neven=i.second;
        }
        return xodd-neven;
    }
};
