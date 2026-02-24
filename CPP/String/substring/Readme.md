**Substring:**
A substring is a contiguous sequence of characters inside a string.

Example:
        
    string s = "abcdef";

Substrings:

    "a", "ab", "abc", "bcd", "cdef", etc.
** Using substr() in C++:**
C++ provides a built-in function:

        string substr (size_t pos = 0, size_t len = npos) const;
✅ Syntax
        
        string sub = s.substr(start_index, length);
✅ Example

        #include <iostream>
        using namespace std;
        
        int main() {
            string s = "abcdef";
            string sub = s.substr(2, 3);
            cout << sub;  // Output: cde
        }
**Generate All Substrings (Brute Force)**

Method 1: Using start & length

        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                string sub = s.substr(i, len);
                cout << sub << endl;
            }
        }
Time Complexity:  O(N³)

O(N²) substrings

O(N) copy time for each substring

Method 2: Using start & end index

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                cout << sub << endl;
            }
        }

Here: Length = j - i + 1
