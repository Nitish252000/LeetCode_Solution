class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> compressed;
        compressed.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])compressed.push_back(nums[i]);
        }
        int cnt=0;
        for(int i=1;i<compressed.size()-1;i++){
            if (compressed[i] > compressed[i - 1] && compressed[i] > compressed[i + 1]) 
                cnt++; // hill
            else if (compressed[i] < compressed[i - 1] && compressed[i] < compressed[i + 1])
                cnt++; // valley
        }
        return cnt;
    }
};
