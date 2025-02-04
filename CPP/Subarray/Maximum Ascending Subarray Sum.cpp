class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int currs=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[j-1]){
                    currs+=nums[j];
                }else{
                    break;
                }
            }
            maxi=max(maxi,currs);
        }
        return maxi;
    }
};
