class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        auto rev = [](int num) {
            int rev_num = 0;
            while (num > 0) {
                int last = num % 10;
                rev_num = rev_num * 10 + last;
                num /= 10;
            }
            return rev_num;
        };
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (mp.count(val)) {
                ans = min(ans, abs(i - mp[val]));
            }
            mp[rev(val)] = i;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
