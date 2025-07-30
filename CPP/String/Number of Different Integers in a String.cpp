class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> st;
        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i])) {
                string num;
                while (i<word.size() && isdigit(word[i])){
                    num+=word[i];
                    i++;
                }
                // remove leading zero
                int j=0;
                while(j<num.size() && num[j]=='0')j++;
                string res=num.substr(j);
                if(res.size()==0)st.insert("0");
                else
                st.insert(res);
            }
        }
        return st.size();
    }
};
