class Solution {
public:
    void findCombination(vector<int>&can, int tar, int start, vector<int>&st, vector<vector<int>>&ans){
        if(tar==0){
            ans.push_back(st);
            return;
        }
        for(int i=start;i<can.size();i++){
            if(i>start && can[i]==can[i-1])continue;
            if(can[i]>tar)break;
            st.push_back(can[i]);
            findCombination(can,tar-can[i],i+1,st,ans);
            st.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>store;
        sort(candidates.begin(),candidates.end());
        findCombination(candidates, target, 0, store, ans);
        return ans;
    }
};
