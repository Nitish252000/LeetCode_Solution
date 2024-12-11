class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        //-------------------will give TLE-------------
        /*unordered_map<int, int> frequency;        
        // Adjust each element to the range [nums[i] - k, nums[i] + k]
        for (int num : nums) {
            for (int adjusted = num - k; adjusted <= num + k; ++adjusted) {
                frequency[adjusted]++;
            }
        }
        // Find the maximum frequency of any number
        int maxBeauty = 0;
        for (const auto& [key, count] : frequency) {
            maxBeauty = max(maxBeauty, count);
        }
        return maxBeauty;*/
        sort(nums.begin(),nums.end());
        int left =0, maxBeauty=0;
        for (int right=0;right<nums.size();right++){
            while((nums[right]-nums[left])>2*k){
                left++;
            }
            maxBeauty = max(maxBeauty, right-left+1);
        }
        return maxBeauty;
    }
};
