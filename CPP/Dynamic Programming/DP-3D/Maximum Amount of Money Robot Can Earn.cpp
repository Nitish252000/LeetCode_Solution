class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows = coins.size();
        int cols = coins[0].size();

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(3, INT_MIN)));


        // Base case
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // skip robber
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }

                    int val = coins[i][j];

                    // From top
                    if (i > 0) {
                        if (dp[i-1][j][k]!=INT_MIN){
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + val);
                        }
                        if(val<0 && k>0 && dp[i-1][j][k-1]!=INT_MIN){
                            dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]);
                        }
                    }

                    // From left
                    if(j>0){
                        if(dp[i][j-1][k]!=INT_MIN){
                            dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k]+val);
                        }
                        if(val<0 && k>0 && dp[i][j-1][k-1]!=INT_MIN){
                            dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]);
                        }
                    }
                }
            }
        }
        return max({dp[rows-1][cols-1][0], dp[rows-1][cols-1][1], dp[rows-1][cols-1][2]});
    }
};
