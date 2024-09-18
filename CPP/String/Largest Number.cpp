class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>st;
        for(auto num:nums){
            st.push_back(to_string(num));
        }
        sort(st.begin(),st.end(),[](string &a, string &b){
            return a+b>b+a;
        });
        if(st[0]=="0")return "0";
        string larg;
        for(auto i:st){
            larg=larg+i;
        }
        return larg;
    }
};
