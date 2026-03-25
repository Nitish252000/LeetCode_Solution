class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i=left;i<=right;i++){
            bool check = false;
            for(auto range:ranges){
                int start = range[0];
                int end = range[1];

                if(i>=start && i<=end){
                    check =true;
                    break;
                }
            }
            if(check==false){
                return false;
            }
        }
        return true;
    }
};
