class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0, total = 0;
        for (int left = 0, right = 0; right < n; right++) {
            total += nums[right];
            while (left <= right && total * (right - left + 1) >= k) {
                total -= nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
};
