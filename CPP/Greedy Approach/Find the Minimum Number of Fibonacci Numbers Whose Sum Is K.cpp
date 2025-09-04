class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1, 1};
        while (fib[fib.size() - 1] <= k) {
            fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        }
        int cnt = 0;
        int i = fib.size() - 1;
        while (k > 0) {
            if (fib[i] <= k) {
                k -= fib[i];
                cnt++;
            }
            i--;
        }
        return cnt;
    }
};
