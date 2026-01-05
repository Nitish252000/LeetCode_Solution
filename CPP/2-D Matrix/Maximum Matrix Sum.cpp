class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long maxi_sum = 0;
        int neg_cnt = 0;
        int minAbsnum = INT_MAX;

        for (auto row : matrix) {
            for (auto val : row) {
                if (val < 0) {
                    neg_cnt++;
                }
                maxi_sum += abs(val);
                minAbsnum = min(minAbsnum, abs(val));
            }
        }
        return neg_cnt % 2 == 1 ? maxi_sum - 2 * minAbsnum : maxi_sum;
    }
};


// Why subtract twice the smallest absolute value? 
// For an odd count of negative numbers, flipping a negative number to positive adds that number's absolute value to the total sum. For example, if we had flipped -1 to +1, it would increase the sum by +1. However, since we can't flip this number (due to the odd count of negatives), we need to "remove" this potential gain. This is why we subtract twice the smallest absolute value: once to account for the gain we didn’t get and again because we didn’t flip it.
