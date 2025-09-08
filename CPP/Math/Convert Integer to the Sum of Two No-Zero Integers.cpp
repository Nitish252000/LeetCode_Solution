class Solution {
public:
    bool isContainZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) {
                return false;
            }
            n = n / 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isContainZero(a) && isContainZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};
