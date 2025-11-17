class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curr_idx = 0, prev_idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curr_idx = i;
                if (prev_idx != -1 && (curr_idx - prev_idx - 1) < k)
                    return false;
                
                prev_idx = curr_idx;
            }
        }
        return true;
    }
};

