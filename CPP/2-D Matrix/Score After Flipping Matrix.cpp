  int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //Check first element 
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                //flip the row
                for(int j=0;j<n;j++){
                    grid[i][j] = 1-grid[i][j];
                }
            }
        }
      // Now Setup element except first column
        for(int j=1;j<n;j++){
            int cz = 0;
            //Count zero
            for(int i=0;i<m;i++){
                if(grid[i][j]==0)cz++;
            }
            //if number of 0's  is greater than 1's, Flip the column
            if(cz>m-cz){
                for(int i=0;i<m;i++){
                    grid[i][j] = 1-grid[i][j];
                }
            }
        }
      //Calculation of final score
        int ans=0;
        for(int i=0;i<m;i++){
            int res=0;
            for(int j=0;j<n;j++){
                res=res+pow(2,n-j-1)*grid[i][j];
            }
            ans=ans+res;
        }
        return ans;
    }
