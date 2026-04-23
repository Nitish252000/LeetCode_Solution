class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Method 1:  T.C = O(N) , S.C = O(N)
        // vector<int> ans;
        // unordered_map<int, int> mp;
        // for (auto& num : nums) {
        //     mp[num]++;
        // }
        // for (auto i : mp) {
        //     if (i.second > 1) {
        //         ans.push_back(i.first);
        //     }
        // }
        // return ans;

        // Method 2: Sign Marking Trick (If the array contains integers from 1
        // to n)
        vector<int> ans;
        for (auto& num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                ans.push_back(abs(num));
            } 
            else {
                nums[idx] *= -1;
            }
        }
        return ans;
    }
};
