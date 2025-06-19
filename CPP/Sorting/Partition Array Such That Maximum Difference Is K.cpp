class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int mini=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-mini>k){
                cnt++;
                mini=nums[i];
            }
        }
        // +1 bcz counting the first group
        return cnt+1;
    }
};
