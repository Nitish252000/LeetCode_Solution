class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])>diff){
                diff=abs(nums[i]-nums[i+1]);
            }
        }
        return max(diff,abs(nums[0]-nums[nums.size()-1]));
    }
};
