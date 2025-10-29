class Solution {
public:
    int smallestNumber(int n) {
        // All 1s” number (1, 3, 7, 15, 31, 63, ...), 
        // Loop-based approach builds 1, 3, 7, 15, 31, ... 
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
};
