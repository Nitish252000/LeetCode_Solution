class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int mini = INT_MAX;
        for (auto& i : mp) {
            vector<int>& v = i.second;
            if (v.size() >= 3) {
                for (int idx = 0; idx + 2 < v.size(); idx++) {
                    mini = min(mini, abs(v[idx] - v[idx + 1]) +
                                         abs(v[idx + 1] - v[idx + 2]) +
                                         abs(v[idx] - v[idx + 2]));
                }
            }
        }
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};
