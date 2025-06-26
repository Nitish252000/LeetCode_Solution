class Solution {
public:
    string convert(string str){
        int n=stoi(str);
        string res;
        while(n!=0){
            res=to_string(n&1)+res;
            n=n>>1;
        }
        return res+"-";
    }

    string convertDateToBinary(string date) {
        string ans;
        stringstream ss(date);
        string word;
        while(getline(ss,word,'-')){
            ans+=convert(word);
        }
        ans.pop_back(); // remove the last character
        return ans;
    }
};
