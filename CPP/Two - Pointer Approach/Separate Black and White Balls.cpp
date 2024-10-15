class Solution {
public:
    long long minimumSteps(string s) {
        long long totalswap=0;
        int whitepos = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                totalswap+=i-whitepos;
                whitepos++;
            }
        }
        return totalswap;
    }
};
