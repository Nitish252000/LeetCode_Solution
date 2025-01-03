class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>prefSum;
        prefSum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            prefSum.push_back(prefSum[i-1]+nums[i]);
        }
        int cnt =0;
        int n =nums.size();
        for(int i=0;i<nums.size()-1;i++){
            long long leftSum=prefSum[i];
            long long rightSum=prefSum[n-1]-prefSum[i];
            if(leftSum>=rightSum)cnt++;
        }
        return cnt;
    }
};
