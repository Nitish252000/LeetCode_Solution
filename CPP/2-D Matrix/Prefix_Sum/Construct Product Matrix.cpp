class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int MOD = 12345;

        // Handling zeros and overflow becomes problematic here

        // long long total_p = 1;
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         total_p=(total_p*grid[i][j])%MOD;
        //     }
        // }

        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         grid[i][j]=total_p/grid[i][j]);   // element is zero then
        //         total_p/0  (crash / undefined)
        //     }
        // }
        // return grid;

        vector<vector<int>> p(rows, vector<int>(cols));

        // Create Flattened array
        int n = rows * cols;
        vector<int> arr;
        for (auto row : grid) {
            for (auto num : row) {
                arr.push_back(num%MOD);
            }
        }
        vector<long long> prefix(n, 1);
        vector<long long> suffix(n, 1);

        // Fill prefix
        for (int i = 1; i < n; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }
        // Fill suffix
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        // Build Product
        for (int i = 0; i < n; i++) {
            p[i/cols][i%cols]=(prefix[i]*suffix[i])%MOD;
        }
        return p;
    }
};
