class Solution {
public:
    bool helper(int n) {
        int cnt = 0;
        while (n != 0) {
            int bit=n&1;
            if (bit == 1)
                cnt++;
            n >>= 1;
        }

        // 0 and 1 are not prime
        if (cnt < 2) return false;

        for (int i = 2; i <= cnt / 2; i++) {
            if (cnt % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (helper(i))
                ans++;
        }
        return ans;
    }
};
