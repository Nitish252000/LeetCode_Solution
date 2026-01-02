class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<int, pair<string, string>> mp;
        int k = indices.size();
        for (int i = 0; i < k; i++) {
            int idx = indices[i];
            string src = sources[i];
            string targ = targets[i];

            if (s.substr(idx, src.size()) == src) {
                mp[idx] = {src, targ};
            }
        }

        string ans;
        int i = 0;
        while (i < s.size()) {
            // If there is a replacement starting at position i
            if (mp.find(i) != mp.end()) {
                ans += mp[i].second;  // append target string
                i += mp[i].first.size();  // skip the source length
            } else {
                ans += s[i];  // no replacement, just copy current char
                i++;
            }
        }
        
        return ans;

    }
};
