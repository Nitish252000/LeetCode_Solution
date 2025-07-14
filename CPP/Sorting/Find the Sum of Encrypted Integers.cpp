class Solution {
public:
    int encrypt(int num){
        string str=to_string(num);
        sort(str.begin(),str.end());
        int n=str.size();
        string res;
        for(int i=0;i<n;i++){
            res+=str[n-1];
        }
        return stoi(res);
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=encrypt(nums[i]);
        }
        return ans;
    }
};
