class Solution {
public:
    void findCombination(vector<int>&can, int tar, int start,
vector<int>& curr, vector<vector<int>>& ans) {
        if (tar == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < can.size(); i++) {
            if(can[i]>tar)continue;
            // Include the current candidate and recurse
            curr.push_back(can[i]);
            findCombination(can, tar - can[i], i, curr, ans);
            curr.pop_back(); // Backtrack to try the next candidate
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        findCombination(candidates, target, 0, curr, ans);
        return ans;
    }
};
