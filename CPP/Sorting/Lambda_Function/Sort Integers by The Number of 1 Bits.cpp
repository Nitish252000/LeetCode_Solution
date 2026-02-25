class Solution {
public:
    int helper(int n) {
        int cnt1 = 0;
        while (n != 0) {
            int bit = n & 1;
            if (bit == 1) {
                cnt1++;
            }
            n >>= 1;
        }
        return cnt1;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : arr) {
            int f = helper(num);
            mp[num] = f;
        }
        sort(mp.begin(), mp.end(), [](const auto &a, const auto &b) { a.second < b.second; });
        for (auto m : mp) {
            ans.push_back(m.first);
        }
        return ans;
    }
};
