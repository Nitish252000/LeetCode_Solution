class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>rowMin;
       // Find the minimum value in each row
        for(int i=0;i<r;i++){
            int mini=INT_MAX;
            for(int j=0;j<c;j++){
                if(matrix[i][j]<mini){
                    mini=matrix[i][j];
                }
            }
            rowMin.push_back(mini);
        }
       // Find the maximum value in each column
        vector<int>colMax;
        for(int j=0;j<c;j++){    
            int maxi=INT_MIN;
            for(int i=0;i<r;i++){
                if(matrix[i][j]>maxi){
                    maxi=matrix[i][j];
                }
            }
            colMax.push_back(maxi);
        }
        // Find the lucky numbers
        // vector<int> ans;
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
        //             ans.push_back(matrix[i][j]);
        //         }
        //     }
        // }
                //OR
        // Find the intersection of rowMin and colMax
        vector<int> ans;
        for (int i = 0; i < rowMin.size(); i++) {
            for (int j = 0; j < colMax.size(); j++) {
                if (rowMin[i] == colMax[j]) {
                    ans.push_back(rowMin[i]);
                }
            }
        }
        return ans;
    }
};
