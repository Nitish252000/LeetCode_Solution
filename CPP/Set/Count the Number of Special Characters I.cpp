class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, int> mp;
        set<char> st;
        for (auto c : word) {
            mp[c]++;
            st.insert(c);
        }
        int ans = 0;
        for (auto i : st) {
            // Consider only lowercase letters
            if (i >= 'a' && i <= 'z') {
                // Check if the corresponding uppercase version of this letter
                // exists in the string
                if (mp.find(toupper(i)) != mp.end())
                    ans++; // If both lowercase and uppercase exist, count this
                           // as a special character
            }
            // else{
            //     if(mp.find(tolower(i))!=mp.end())ans++;
            // }
        }
        return ans;
    }
};
