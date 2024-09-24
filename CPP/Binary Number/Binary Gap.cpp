class Solution {
public:
    string decimaltoBinary(int n){
        string str;
        while(n!=0){
            int rem = n%2;
            str=to_string(rem)+str;
            n=n/2;
        }
        return str;
    }
    int binaryGap(int n) {
        string str = decimaltoBinary(n);
        int ans = 0;
        vector<int>onesIndex;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1' ){
                onesIndex.push_back(i);
            }
        }
        for(int i=0;i<onesIndex.size()-1;i++){
            ans=max(ans,onesIndex[i+1]-onesIndex[i]);
        }
        return ans;
    }
};
