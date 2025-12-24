class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }
        int itr = 1;
        while (true) {
            int val = k * itr;
            if (!st.count(val))
                return val;
            itr++;
        }
    }
};
