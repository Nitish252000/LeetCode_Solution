 int specialArray(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // Iterate through all possible values of x
        for (int x = 1; x <= n; x++) {
          // Find the number of elements >= x
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] >= x){
                    cnt++;
                }
            }
          // Check if the count equals x
            if(cnt == x){
                return x;
            }
        }
       // If no such x is found, return -1
        return -1;
}
