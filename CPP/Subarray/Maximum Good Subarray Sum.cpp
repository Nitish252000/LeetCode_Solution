class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // ------------- Will give TLE : Time Limit Exceeded 776 / 783 testcases
        // passed ------------------------------- long long maxi = LLONG_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     long long sum = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         sum +=nums[j];
        //         if (abs(nums[i] - nums[j]) == k) {
        //             maxi = max(maxi, sum);
        //         }
        //     }

        // }
        // if(maxi == LLONG_MIN)return 0;
        // return maxi;

        // Method 2: HashMap + Prefix Sum

        unordered_map<int, long long> mp;
        long long sum = 0;
        long long maxi = LLONG_MIN;
        for (auto num : nums) {
            if (mp.find(num+k)!=mp.end()){
                maxi = max(maxi, sum+num-mp[num+k]);
            }
            if (mp.find(num-k)!=mp.end()){
                maxi = max(maxi, sum+num-mp[num-k]);
            }
            if(mp.find(num)==mp.end()){
                mp[num]=sum;
            }
            else
                mp[num] = min(mp[num], sum);
            sum+=num;
        }

        return maxi==LLONG_MIN?0:maxi;
    }
};
