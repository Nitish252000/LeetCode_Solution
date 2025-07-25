class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        for(auto num:nums){
            if(num>0){
                st.insert(num);
            }
        }
        if(st.size()==0)return *max_element(nums.begin(),nums.end());
        return accumulate(st.begin(),st.end(),0);
    }
};
