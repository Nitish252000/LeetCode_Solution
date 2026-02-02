class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //---------- T.C = O(N) ----------------
        // for (auto ch : letters)
        //     if (ch > target)
        //         return ch;
        // return letters[0];

        // -------Binary Search, T.C = O(logN);---------------
        // int start = 0;
        // int end = letters.size() - 1;
        // if (target >= letters[end])
        //     return letters[0];
        // while (start <= end) {
        //     int mid = start + (end - start) / 2;
        //     if (letters[mid] > target) {
        //         end = mid - 1;
        //     } else {
        //         start = mid + 1;
        //     }
        // }
        // return letters[start];

        //---- Using upper_bound() stl function: returns an iterator to the
        //first element strictly greater than target --------

        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};
