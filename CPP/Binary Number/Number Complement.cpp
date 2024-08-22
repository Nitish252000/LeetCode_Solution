class Solution {
public:
    int bTod(string s){
        int j=0;
        int num=0;
        for(int i=s.size()-1;i>=0;i--){
            int bit = s[i]-'0';
            num+=pow(2,j)*bit;
            j++;
        }
        return num;
    }
    string dTob(int num){
        if (num == 0) return "0";
        string s;
        while(num>1){
            int rem =num%2;
            s=to_string(rem)+s;
            num=num/2;
        }
        return s;
    }
    int findComplement(int num) {
        string binary = dTob(num);
        for(int i=0;i<binary.size();i++){
            if(binary[i]=='0')binary[i]='1';
            else binary[i]='0';
        }
        return bTod(binary);
    }
};
