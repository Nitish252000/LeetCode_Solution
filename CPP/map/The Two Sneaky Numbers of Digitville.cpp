class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        for (auto i : mp) {
            if (i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
