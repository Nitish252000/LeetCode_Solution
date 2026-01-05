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
