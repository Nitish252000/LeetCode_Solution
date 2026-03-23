class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<long long>>maxP(rows, vector<long long>(cols));
        vector<vector<long long>>minP(rows, vector<long long>(cols));
 
        // fill the matrix
        maxP[0][0] = minP[0][0] = grid[0][0];

        // First Row: Only one way from left
        for(int j=1;j<cols;j++){
            maxP[0][j]= minP[0][j] = maxP[0][j-1]*grid[0][j];
        }

        //First Column: Only way from top
        for(int i=1;i<rows;i++){
            maxP[i][0] = minP[i][0] = maxP[i-1][0]*grid[i][0];
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                long long val = grid[i][j];

                long long topMax = maxP[i-1][j];
                long long topMin = minP[i-1][j];

                long long leftMax = maxP[i][j-1];
                long long leftMin = minP[i][j-1];


                if(val>=0){
                    maxP[i][j]= max(topMax, leftMax)*val;
                    minP[i][j] = min(topMin, leftMin)*val;
                }else{
                    maxP[i][j] = min(topMin, leftMin)*val;
                    minP[i][j] = max(topMax, leftMax)*val;
                }
            }
        }
        long long ans  = maxP[rows-1][cols-1];
        int MOD =1e9+7;
        if(ans<0)return -1;
        return ans%MOD;
    }
};
