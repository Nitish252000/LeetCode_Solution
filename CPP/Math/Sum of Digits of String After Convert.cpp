class Solution {
public:
    int getLucky(string s, int k) {
        string numstr;
        for(auto i:s){
            numstr+=to_string(i-'a'+1);
        }
        while(k>0){
            int digSum = 0;
            for(auto digit:numstr){
                digSum+=digit-'0';
            }
            k--;
            numstr = to_string(digSum);
        }
        return stoi(numstr);
    }
};
