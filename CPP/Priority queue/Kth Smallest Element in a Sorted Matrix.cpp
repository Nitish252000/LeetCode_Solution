class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // vector<int> ans;
        // for (int i = 0; i < rows; i++) {
        //     for (int j = 0; j < cols; j++) {
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // return ans[k - 1];
        priority_queue<int> pq;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                pq.push(matrix[i][j]);
            }
        }
        while (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
