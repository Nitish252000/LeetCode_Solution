class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zrow;
        set<int> zcol;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zrow.insert(i);
                    zcol.insert(j);
                }
            }
        }
        for(auto r:zrow){
            for(int i=0;i<matrix[0].size();i++){
                matrix[r][i]=0;
            }
        }
        for(auto c:zcol){
            for(int j=0;j<matrix.size();j++){
                matrix[j][c]=0;
            }
        }
    }
};
