class Solution {
public:
    string makeFancyString(string s) {
        // Method 1: frequency count 

        /*string ans;
        int fq=1;
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                fq++;
            }
            else{
                fq=1;
            }
            if(fq<3)ans.push_back(s[i]);
        }
        return ans;*/


        // Method 2:  Using Stack Simulation
        string st;
        for(auto ch:s){
            int sz=st.size();
            if(sz>=2 && ch==st[sz-1] && ch==st[sz-2])
                continue; // skip adding 
            st+=ch;
        }
        return st;
    }
};
