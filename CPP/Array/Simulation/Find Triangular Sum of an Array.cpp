class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp;
        temp.push_back(nums);
        for (int i = 0; i < n - 1; i++) {
            vector<int> curr;
            for (int j = 0; j < temp[i].size() - 1; j++) {
                curr.push_back((temp[i][j] + temp[i][j + 1]) % 10);
            }
            temp.push_back(curr);
        }
        return temp[n - 1][0];
    }
};
