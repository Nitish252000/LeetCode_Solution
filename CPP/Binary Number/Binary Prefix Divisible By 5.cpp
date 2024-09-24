class Solution {
public:
    // long long convertBtoD(string s){
    //     int k =0;
    //     long long ans =0;
    //     for(int i=s.size()-1;i>=0;i--){
    //         int bit =s[i]-'0';
    //         ans=ans+pow(2,k)*bit;
    //         k++;
    //     }
    //     return ans;
    // }
    // vector<bool> prefixesDivBy5(vector<int>& nums) {
    //     vector<bool>ans;
    //     string str;
    //     for(int i=0;i<nums.size();i++){
    //         str=str+to_string(nums[i]);
    //         if(convertBtoD(str)%5==0){
    //             ans.push_back(true);
    //         }
    //         else{
    //             ans.push_back(false);
    //         }
    //     }
    //     return ans;
    // }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int currnum =0;
        vector<bool>ans;
        for(auto i:nums){
            currnum =(currnum*2+i)%5;
            if(currnum==0)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};
