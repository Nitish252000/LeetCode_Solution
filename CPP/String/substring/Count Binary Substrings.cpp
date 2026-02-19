class Solution {
public:
    //-----------------Brute force approach : Giving TLE--------------
    // bool isValid(string sub) {
    //     int n = sub.size();
    //     int cnt0 = 0;
    //     int cnt1 = 0;
    //     // Count first group
    //     char first = sub[0];
    //     int i = 0;
    //     while (i < n && sub[i] == first) {
    //         if (sub[i] == '0')
    //             cnt0++;
    //         else
    //             cnt1++;
    //         i++;
    //     }
    //     if (i == n)
    //         return false; // bcz: only one group exist

    //     // Count second group
    //     char second = sub[i];
    //     while (i < n && sub[i] == second) {
    //         if (sub[i] == '0')
    //             cnt0++;
    //         else
    //             cnt1++;
    //         i++;
    //     }
    //     if (i != n)
    //         return false;   // If more characters left → invalid

    //     return cnt0 == cnt1;
    // }
    // int countBinarySubstrings(string s) {
    //     int n = s.size();
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int len = 1; len <= n - i; len++) {
    //             string sub = s.substr(i, len);
    //             if (isValid(sub)) {
    //                 ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    //------ Method 2: 
        // Track previous group length
        // Track current group length
        // Every time character changes:
        // Add min(prev, curr) to answer
        // Update prev = curr
        // Reset curr = 1
        // At end add final min(prev, curr)
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int prev =0;
        int curr = 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                curr++;
            }
            else{
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
        }
        ans+=min(prev,curr);
        return ans;
    }
};
