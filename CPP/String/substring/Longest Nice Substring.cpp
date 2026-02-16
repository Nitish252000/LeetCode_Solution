class Solution {
public:
    bool nice(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) && mp.find(toupper(s[i])) == mp.end())
                return false;
            if (toupper(s[i]) && mp.find(tolower(s[i])) == mp.end())
                return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if (nice(sub)) {
                    if (maxLen < sub.size()) {
                        maxLen = sub.size();
                        ans = sub;
                    }
                }
            }
        }
        return ans;
    }
};
