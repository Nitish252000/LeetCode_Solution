class Solution {
public:
    bool check(int n){
        string s = to_string(n);
        int sum = 0;
        for(auto i:s){
            sum+=i-'0';
        }
        if(sum%2==0)return true;
        return false;
    }
    int countEven(int num) {
        int cnt = 0;
        for(int i=1;i<=num;i++){
            if(check(i)){
                cnt++;
            }
        }
        return cnt;
    }
};
