class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> digits;
        for (auto i : s) {
            digits.push_back(i - '0');
        }
        while (digits.size() > 2) {
            for (int i = 0; i+1 < digits.size(); i++) {
                digits[i] = (digits[i] + digits[i + 1]) % 10;
            }
            digits.pop_back();
        }
        return digits[0] == digits[1];
    }
};
