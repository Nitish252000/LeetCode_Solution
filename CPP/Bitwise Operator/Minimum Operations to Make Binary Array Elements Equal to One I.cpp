class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt =0;
        for(int i=0;i<=nums.size()-3;i++){
            if(nums[i]==0){
                nums[i]^=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
                cnt++;
            }
        }
        for(auto i:nums){
            if(i==0)return -1;
        }
        return cnt;
    }
};
