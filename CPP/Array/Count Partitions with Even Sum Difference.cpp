class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt=0;
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        int curr_sum=0;
        for(int i=0;i<nums.size()-1;i++){
            curr_sum+=nums[i];
            int right_sum=total_sum-curr_sum;
            if((right_sum-curr_sum)%2==0)cnt++;
        }
        return cnt;
    }
};
