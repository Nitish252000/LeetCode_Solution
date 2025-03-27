class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        int dominant;
        int total_count = 0;
        for (auto i : mp) {
            if (i.second > total_count) {
                total_count = i.second;
                dominant = i.first;
            }
        }

        int left_count = 0, right_count = total_count;

        // Iterate and check for a valid split
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == dominant) {
                left_count++;
                right_count--;
            }
            // The dominant element should be present more than half the size of the left subarray
            // Check if dominant element is dominant in both halves
            if (left_count * 2 > (i + 1) &&
                right_count * 2 > (nums.size() - i - 1)) {
                return i;
            }
        }

        return -1; // No valid split found
    }
};
