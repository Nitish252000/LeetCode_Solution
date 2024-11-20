class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['b'] = 0;
        mp['c'] = 0;
        for (auto i : s) {
            mp[i]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;
        int left = 0;
        unordered_map<char, int> windowFreq;
        int maxWindow=0;
        //Find the longest window that leaves k of each character outside
        for (int right = 0; right < s.size(); right++) {
            windowFreq[s[right]]++;
            // Shrink window if we take too many characters
            while (left<=right && (mp['a']-windowFreq['a'] < k || mp['b']-windowFreq['b'] < k || mp['c']-windowFreq['c'] < k)) {  
                // Shrink the window from the left
                windowFreq[s[left]]--;
                left++;
            }
            maxWindow = max(maxWindow,right-left+1);
        }
        return s.size()-maxWindow;
    }
};
