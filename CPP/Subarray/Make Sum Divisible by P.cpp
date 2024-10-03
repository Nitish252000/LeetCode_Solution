class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        /*--Time Limit Exceeded 137 / 142 testcases passed--*/
        // int n=nums.size();
        // long long totalSum = 0;
        // totalSum = accumulate(nums.begin(),nums.end(),0LL);
        // if(totalSum%p==0)return 0;
        // int minlen = n;
        // //every Possible Subarray
        // for(int i=0;i<n;i++){
        //     long long subsum=0;
        //     for(int j=i;j<n;j++){
        //         subsum+=+nums[j];
        //         //check: after removing subarray
        //         long long remsum=totalSum-subsum;
        //         if(remsum%p==0){
        //             minlen=min(minlen,j-i+1);
        //         }
        //     }
        // }
        // //If no valid subarray is found, return -1
        // if(minlen==n){
        //     return -1;
        // }
        // return minlen;
        int n = nums.size();
    
        // Calculate the total sum of the array
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        
        // If the total sum is already divisible by p, no subarray needs to be removed
        int remainder = totalSum % p;
        if (remainder == 0) {
            return 0;
        }
        // HashMap to store the prefix sum modulo p and its corresponding index
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // Initialize to handle cases where prefix sum itself is divisible by p
        int min_len = n;
        long long prefix_sum = 0;
        // Traverse through the array and calculate prefix sums
        for (int i = 0; i < n; ++i) {
            prefix_sum += nums[i];
            int mod = prefix_sum % p;
            mod = (mod + p) % p; // Normalize the modulo to handle negative values           
            // Check if there's a prefix that would make the current sum divisible by p
            int target = (mod - remainder + p) % p;  // Find what we need to remove to make sum divisible by p          
            if (prefix_map.find(target) != prefix_map.end()) {
                min_len = min(min_len, i - prefix_map[target]);
            }            
            // Store the current modulo result in the map
            prefix_map[mod] = i;
        }       
        // If no valid subarray is found, return -1
        return (min_len == n) ? -1 : min_len;
    }
};
