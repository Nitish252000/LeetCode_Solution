class Solution {
public:
    string convert(int n){
        string res;
        while(n!=0){
            int bit=n&1;
            n=n>>1;
            res=to_string(bit)+res;
        }
        return res;
    }
    bool hasAlternatingBits(int n) {
        string str=convert(n);
        for(int i=0;i<str.size()-1;i++){
            if(str[i]==str[i+1])return false;
        }
        return true;
    }
};
