class Solution {
public:
    int check(int n){
        int cnt=0;
        while(n!=0){
            int bit = n&1;
            if(bit==1)cnt++;
            n>>=1;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(check(i)==k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};
