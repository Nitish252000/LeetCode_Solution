class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());

        //check if making the uni-value is possible
        int base = nums[0];
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]-base)%x!=0)return -1;
        }

        // find median
        int mid = nums[nums.size()/2];

        int operation =0;
        for(auto num:nums){
            operation+=abs(num-mid)/x;
        }
        return operation;
    }
};
