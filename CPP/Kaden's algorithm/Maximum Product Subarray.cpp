class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currP=1;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currP=currP*nums[i];
            if(currP>mx){
                mx=currP;
            }
            if(currP==0){
                currP=1;
            }
        }
        currP=1;
        for(int i=nums.size()-1;i>=0;i--){
           currP=currP*nums[i];
            if(currP>mx){
                mx=currP;
            }
            if(currP==0){
                currP=1;
            } 
        }
        return mx;
    }
};
