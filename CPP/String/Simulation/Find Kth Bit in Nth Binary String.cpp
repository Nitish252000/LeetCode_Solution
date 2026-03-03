class Solution {
public:
    string inv(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1')
                str[i] = '0';
            else
                str[i] = '1';
        }
        return str;
    }
    string rev(string str) {
        reverse(str.begin(), str.end());
        return str;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        
        for (int i = 1; i < n; i++) {
            string prev = s;
            s = prev + '1' + rev(inv(prev));
            prev = s;
        }
        return s[k-1];
    }
};
