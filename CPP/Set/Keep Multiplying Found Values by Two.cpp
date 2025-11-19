class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }
        int target = original;
        while (st.count(target)) {
            target = 2 * target;
        }
        return target;
    }
};
