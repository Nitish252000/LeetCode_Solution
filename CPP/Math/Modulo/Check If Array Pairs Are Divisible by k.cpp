class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        // int n = arr.size();
        // int cnt = 0;
        // for (int i = 0; i < arr.size(); i++) {
        //     for (int j = i + 1; j < arr.size(); j++) {
        //         int pairsum = arr[i] + arr[j];
        //         if (pairsum % k == 0) {
        //             cnt++;
        //             if (cnt == n / 2) {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        unordered_map<int,int>remCnt;
        for(auto num:nums){
            remCnt[((num%k)+k)%k]++;
        }
        for(auto i:nums){
            int rem = ((i%k)+k)%k;

            if(rem == 0){
                if(remCnt[rem]%2==1)return false;
            }
            else if(remCnt[rem]!=remCnt[k-rem]){
                return false;
            }
        }
        return true;
    }
};
