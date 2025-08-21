class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int total=0;
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==1){
                    if(i==0 || j==0){
                        dp[i][j]=1; //first row/col
                    }
                    else{
                        dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    }
                }
                total+=dp[i][j];
            }
        }
        return total;
    }
};
