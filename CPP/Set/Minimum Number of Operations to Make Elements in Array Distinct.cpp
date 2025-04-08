class Solution {
public:
    bool check (vector<int>&nums, int index){
        set<int>st;
        for (int i = index; i < nums.size(); i++) {
        if (st.count(nums[i])) {
            return false; // found duplicate
        }
        st.insert(nums[i]);
    }
    return true; // all unique
    }
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i+=3){
            if(check(nums,i))break;
            ans++;
        }
        return ans;
    }
};
