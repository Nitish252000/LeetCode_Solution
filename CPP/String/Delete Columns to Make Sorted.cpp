class Solution {
public:
    // bool isSorted(vector<string> strs, int j) {
    //     for (int i = 1; i < strs.size(); i++) {
    //         if (strs[i][j] < strs[i - 1][j]) {
    //             return false; // Not sorted
    //         }
    //     }
    //     return true; //sorted
    // }
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        // Iterate the string column wise
        for (int j = 0; j < strs[0].size(); j++) {
            // if (!isSorted(strs, j))  // if not sorted, delete
            //     ans++;
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ans++; // Not sorted
                    break;
                }
            }
        }
        return ans;
    }
};
