class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        // vector<int> num;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            // int sum = 0;
            for (int j = start; j <= i; j++) {
                sum += nums[j];
            }
            // num.push_back(sum);
        }
        /*int tsum = 0;
        tsum = accumulate(num.begin(), num.end(), tsum);
        return tsum;*/

        // return accumulate(num.begin(), num.end(), 0);
        return sum;
    }
};
