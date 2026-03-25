// I compute total sum, then simulate horizontal and vertical cuts using prefix sums. At each cut, I compare the sum of one side with the remaining part. If both are equal and non-empty, I return true.

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Total Sum
        long long tsum = 0;
        for (auto &g : grid) {
            for (int x : g) {
                tsum += x;
            }
        }

        // Horizonatal cut
        long long topSum=0;
        for (int i = 0; i < rows-1; i++) {  // ensure both parts non-empty
            for (int j = 0; j < cols; j++) {
                topSum+= grid[i][j];
            }
            if (topSum * 2 == tsum)
                return true;
        }

        // Vertical cut
        long long leftSum = 0;
        for (int j = 0; j < cols-1; j++) { // ensure both parts non-empty
            for (int i = 0; i < rows; i++) {
                leftSum += grid[i][j];
            }
            if (leftSum * 2 == tsum)
                return true;
        }
        return false;
    }
};
