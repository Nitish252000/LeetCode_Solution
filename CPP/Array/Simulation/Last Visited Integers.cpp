class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int>ans;
        vector<int>seen;
        int k = 0;
        for(auto num:nums){
            if(num>=0){
                seen.push_back(num);
                k=0;
            }
            else{
                k++;
                if(k<=seen.size()){
                    ans.push_back(seen[seen.size()-k]);
                }   
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
