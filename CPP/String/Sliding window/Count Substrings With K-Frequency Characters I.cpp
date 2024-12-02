class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int cnt = 0; int left = 0;
        unordered_map<char,int>mp;
        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            while (mp[s[right]]>=k){
                mp[s[left]]--;
                cnt+=s.size()-right; //Number of substrings starting from left index.
                left++;
            }
        }
        return cnt;
    }
};
