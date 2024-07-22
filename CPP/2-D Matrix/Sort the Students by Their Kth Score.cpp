class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>>ans;
        vector<pair<int,vector<int>>>st;
        for(int i=0;i<score.size();i++){
            st.push_back({score[i][k], score[i]});
        }
        sort(st.begin(),st.end());
        for(int i=score.size()-1;i>=0;i--){
            ans.push_back(st[i].second);
        }
        return ans;
    }
};
