class Solution {
public:
    //----------TLE (T.C = O(n^2))----------
    // bool check(int num1,int num2){
    //     int sum1=0;
    //     while(num1!=0)
    //     {
    //         sum1+=num1%10;
    //         num1=num1/10;
    //     }
    //     int sum2=0;
    //     while(num2!=0)
    //     {
    //         sum2+=num2%10;
    //         num2=num2/10;
    //     }
    //     return sum1==sum2;
    // }
    // int maximumSum(vector<int>& nums) {
    //     int maxi=INT_MIN;
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(check(nums[i],nums[j])){
    //                 maxi=max(maxi,nums[i]+nums[j]);
    //             }
    //         }
    //     }
    //     if(maxi==INT_MIN)return -1;
    //     return maxi;
    // }

 //--------O(n log n) (efficiently grouping & sorting)-------------
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[digitSum(nums[i])].push_back(nums[i]);
        }
        int maxi=-1;
        for(auto [sum,val]:mp){
            if(val.size()>1){
                sort(val.rbegin(),val.rend());
                maxi=max(maxi,val[0]+val[1]);
            }
        }
        return maxi;
    }
    int digitSum(int num){
        int sum=0;
        while(num!=0)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
};
