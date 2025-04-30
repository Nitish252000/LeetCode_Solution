class Solution {
public:
    bool check (int num){
        int cnt=0;
        while(num!=0){
            cnt++;
            num=num/10;
        }
        if(cnt%2==0)return true;
        return false;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            if(check(i))ans++;
        }
        return ans;
    }
};
