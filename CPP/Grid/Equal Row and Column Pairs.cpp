class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        for(auto row:grid){
            mp[row]++;
        }
        int cnt=0;
        for(int j=0;j<grid.size();j++){
            vector<int>col;
            for(int i=0;i<grid.size();i++){
                col.push_back(grid[i][j]);
            }
            cnt+=mp[col];
        }
        return cnt;
    }
};
