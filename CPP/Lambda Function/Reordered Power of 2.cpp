class Solution {
public:
    bool reorderedPowerOf2(int n) {
      // Helper function: sort digits of a number
        auto sortedDigits = [](int num) {
            string str = to_string(num);
            sort(str.begin(), str.end());
            return str;
        };
        string target = sortedDigits(n);
     // Check all powers of 2 up to 10^9 (for int range)
        for (int i = 0; i < 31; i++) {
            if (sortedDigits(1 << i) == target) {
                return true;
            }
        }
        return false;
    }
};



// How it works
// sortedDigits:

// Turns a number into a string

// Sorts the string’s characters → gives a canonical representation of its digit multiset.

// target:

// Sorted digits of n.

// Loop:

// Check all 2^i values (i = 0 to 30 for 32-bit ints)

// If any sorted digits match, return true.
