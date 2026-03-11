class Solution {
public:
    string dTob(int n) {
        string ans;
        while (n != 0) {
            int bit = n & 1;
            ans = to_string(bit) + ans;
            n >>= 1;
        }
        return ans;
    }
    int btod(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            num = num * 2 + s[i] - '0';
        }
        return num;
    }  
    int bitwiseComplement(int n) {
        int ans = 0;
        string str = dTob(n);
        if(n==0)return 1;
        for (int c =0;c<str.size();c++) {
            if (str[c] == '1')
                str[c]= '0';
            else
                str[c]= '1';
        }
        return btod(str);
    }
};
