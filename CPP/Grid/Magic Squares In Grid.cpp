class Solution {
public:
    bool isMagic(vector<vector<int>>&grid, int rows, int cols){
        set<int>st;
        for(int i=rows;i<rows+3;i++){
            for(int j=cols;j<cols+3;j++){
                int num=grid[i][j];
                if(num<1 || num>9 ||st.find(num)!=st.end()){
                    return false;
                }
                st.insert(num);
            }
        }
        //diagonal sum
        int diag1=grid[rows][cols]+grid[rows+1][cols+1]+grid[rows+2][cols+2];
        int diag2=grid[rows][cols+2]+grid[rows+1][cols+1]+grid[rows+2][cols];
        if(diag1!=diag2)return false;
        //row sum
        for(int i=rows;i<rows+3;i++){
            if(diag1!=grid[i][cols]+grid[i][cols+1]+grid[i][cols+2]){
                return false;
            }
        }
        //col sum
        for(int i=cols;i<cols+3;i++){
            if(diag1!=grid[rows][i]+grid[rows+1][i]+grid[rows+2][i]){
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rz=grid.size();
        int cz=grid[0].size();
        if(rz<3 || cz<3)return false;
        int ans=0;
        for(int rows=0;rows+2<rz;rows++){
            for(int cols=0;cols+2<cz;cols++){
                if(isMagic(grid,rows,cols)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
