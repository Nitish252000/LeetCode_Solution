class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // int n = s.size();
        // unordered_set<string> st;
        // for (int i = 0; i < n - 2; i++) {
        //     for (int j = i + 1; j < n - 1; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             if (s[i] == s[k]) {
        //                 string str = {s[i], s[j], s[k]};
        //                 st.insert(str);
        //             }
        //         }
        //     }
        // }
        // return st.size();
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record first and last occurrences
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        // For each character A...Z, count unique middle characters
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c])
                continue;

            unordered_set<char> middle;

            for (int i = first[c] + 1; i < last[c]; i++) {
                middle.insert(s[i]);
            }

            ans += middle.size();
        }

        return ans;
    }
};
