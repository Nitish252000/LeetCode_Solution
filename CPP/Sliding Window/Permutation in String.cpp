class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string sorted1=s1;
        sort(sorted1.begin(),sorted1.end());
        if(s2.size()<s1.size())return false;
        for(int i=0;i<=s2.size()-s1.size();i++){
            string window=s2.substr(i,s1.size());
            sort(window.begin(),window.end());
            if(sorted1==window)return true;
        }
        return false;
    }
};
