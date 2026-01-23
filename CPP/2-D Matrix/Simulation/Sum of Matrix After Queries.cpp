class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        //------Method 1: Brute force : Will give Memory Limit Exceeded -----
        // vector<vector<int>> mat(n, vector<int>(n, 0));
        // for (auto q : queries) {
        //     int type = q[0];
        //     int index = q[1];
        //     int val = q[2];
        //     if (type == 0) {
        //         for (int j = 0; j < n; j++) {
        //             mat[index][j] = val;
        //         }
        //     } else {
        //         for (int i = 0; i < n; i++) {
        //             mat[i][index] = val;
        //         }
        //     }
        // }

        // long long ans = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         ans += mat[i][j];
        //     }
        // }
        // return ans;

        // Instead of simulating the matrix, I process queries in reverse and
        // only count the first occurrence of each row or column using sets
        long long ans = 0;
        set<int> r_seen, c_seen;
        int rem_r = n, rem_c = n;
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];
            if (type == 0) {
                if (r_seen.count(index))
                    continue;
                ans += val * rem_c;
                r_seen.insert(index);
                rem_r--;
            } else {
                if (c_seen.count(index))
                    continue;
                ans += val * rem_r;
                c_seen.insert(index);
                rem_c--;
            }
        }
        return ans;
    }
};
