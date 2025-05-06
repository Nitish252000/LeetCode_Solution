class Solution {
public:
    long long smallestNumber(long long num) {
        if (num < 0) {
            string s = to_string(-num);
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        }
        if (num == 0)
            return 0;

        string str = to_string(num);
        sort(str.begin(), str.end());
        int cnt = 0;
        int i = 0;
        while (i < str.size() && str[i] == '0') {
            i++;
        }
        swap(str[0], str[i]);
        return stoll(str);
    }
};
