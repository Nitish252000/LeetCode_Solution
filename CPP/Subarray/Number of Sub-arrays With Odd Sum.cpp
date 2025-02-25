class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        //-----------Give TLE---------------
        /*int cnt=0;
        int MOD=1e9+7;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum%2==1)cnt++;
            }
        }
        return cnt%MOD;*/
        int odd=0; int even=0;
        int MOD=1e9+7;
        int sum=0;
        int cnt=0;
        for(auto num:nums){
            sum+=num;
            if(sum%2==0){
                cnt+=odd;
                even++;
            }else{
                cnt=(cnt+even+1)%MOD;
                odd++;
            }
        }
        return cnt%MOD;
    }
};
