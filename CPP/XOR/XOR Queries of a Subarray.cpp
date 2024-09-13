class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto i:queries){
            int op = 0;
            for(int j = i[0];j<=i[1];j++){
                op=op^arr[j];
            }
            ans.push_back(op);
        }
        return ans;
    }
};
