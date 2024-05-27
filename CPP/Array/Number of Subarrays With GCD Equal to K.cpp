int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currGCD = nums[i];
            if(currGCD == k){
                cnt++;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                currGCD = __gcd(currGCD, nums[j]);
                if (currGCD == k)
                    cnt++;
                else if (currGCD < k){
                    break;
                }
            }
        }
        return cnt;
}

// ----------------OR------------
int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currGCD = 0;
            for (int j = i; j < nums.size(); j++) {
                currGCD = __gcd(currGCD, nums[j]);
                if (currGCD == k)
                    cnt++;
            }
        }
        return cnt;
    }
