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


// -Brute-force approach
//     The brute-force approach has a time complexity of O(𝑛2), which is inefficient for large inputs.
//     This logic doesn't ensure that all elements are used in pairs.

// -Remainder-based approach

//     For each element arr[i], compute its remainder when divided by k (i.e., arr[i] % k).
    
//     To form a valid pair, for a number with remainder r, we need another number with remainder (k - r) % k.
    
//     Special cases include handling elements with remainder 0, where we need an even number of such elements.

//      To handle negative numbers, we normalize the remainder using ((num % k) + k) % k.


















