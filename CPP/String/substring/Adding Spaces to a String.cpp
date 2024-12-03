class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        ans+=s.substr(0,spaces[0]);
        ans+=' ';
        int n =s.size();
        for(int i=1;i<spaces.size();i++){
            ans+=s.substr(spaces[i-1],spaces[i]-spaces[i-1]);
            ans+=' ';
        }
        // Add the final segment after the last space
        int ss= spaces.size();
        ans+=s.substr(spaces[ss-1],n-spaces[ss-1]);
        return ans;
    }
};
