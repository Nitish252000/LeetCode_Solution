class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int lbs = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int cnt = mp[s[i]];
                bool flag = true;
                for (auto m : mp) {
                    if (cnt != m.second) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    lbs = max(lbs, j - i + 1);
                }
            }
        }
        return lbs;
    }
};
