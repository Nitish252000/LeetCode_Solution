class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxValue = 0;
        for (int i = 1; i <= n; i++) {
            int key = 0, num = i;
            while (num != 0) {
                key += num % 10;
                num = num / 10;
            }
            mp[key]++;
            maxValue = max(maxValue, mp[key]);
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second==maxValue){
                cnt++;
            }
        }
        return cnt;
    }
};
