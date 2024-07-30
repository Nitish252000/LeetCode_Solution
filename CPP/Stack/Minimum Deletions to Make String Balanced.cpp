class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int n=s.size();
        int delcnt=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                delcnt++;
            }
            else{
                st.push(s[i]);
            }
        }
        return delcnt;
    }
};
