class Solution {
public:
    bool checkString(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                return false;
            }else{
                st.push(s[i]);
            }
        }
        return true;
    }
};
