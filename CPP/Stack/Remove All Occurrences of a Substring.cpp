class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if (st.size()>=part.size() && check(st,part)){
                for(int i=0;i<part.size();i++){
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
    bool check(stack<char>st,string part){
        for(int i=part.size()-1;i>=0;i--){
            if(part[i]!=st.top()){
                return false;
            }
            st.pop();
        }
        return true;
    }
};
