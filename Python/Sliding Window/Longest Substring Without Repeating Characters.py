class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        set<char>st;
        int maxi=0;
        for(int right=0;right<s.size();right++){
            while(st.count(s[right])){ // If char exits in set, shrink with window
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};
