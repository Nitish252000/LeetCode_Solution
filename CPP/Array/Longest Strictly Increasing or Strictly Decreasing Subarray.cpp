class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxl=0;
        //Increasing
        for(int i=0;i<nums.size();i++){
            int currl=1;
            for (int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[j-1]){
                    currl++;
                }else{
                    break;
                }
            }
            maxl=max(maxl,currl);
        }
        //Decreasing
        for(int i=0;i<nums.size();i++){
            int currl=1;
            for (int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[j-1]){
                    currl++;
                }else{
                    break;
                }
            }
            maxl=max(maxl,currl);
        }
        return maxl;
    }
};
