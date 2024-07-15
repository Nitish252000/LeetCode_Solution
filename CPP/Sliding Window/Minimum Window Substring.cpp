class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> tfreq;
        for (auto i : t) {
            tfreq[i]++;
        }
        unordered_map<char, int> windowfreq;
        int left = 0, right = 0;
        int required = tfreq.size(); // Number of unique characters in t that need to be present in the window
        int formed = 0;     // Number of unique characters in the current window that match the required frequency in t
        int minl = INT_MAX; // Length of the minimum window
        int minLeft = 0;    // Start index of the minimum window
        while (right < s.size()) {
            windowfreq[s[right]]++;
            if (tfreq.count(s[right]) && windowfreq[s[right]] == tfreq[s[right]]) {
                formed++;
            }
            while (left <= right && required == formed) {
                char c = s[left];
                if (right - left + 1 < minl) {
                    minl = right - left + 1;
                    minLeft = left;
                }
                // Shrink the window from the left
                windowfreq[c]--;
                if (tfreq.count(c) && windowfreq[c] < tfreq[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        if (minl == INT_MAX)
            return "";
        return s.substr(minLeft, minl);
    }
};
