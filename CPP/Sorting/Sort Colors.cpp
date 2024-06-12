void sortColors(vector<int>& nums) {
       int s = nums.size();
       int r=0,w=0,b=0;
       for(int i:nums){
        if(i==0)r++;
        else if(i==1)w++;
        else b++;
       }
       vector<int>ans;
       for(int i=0;i<r;i++){
        ans.push_back(0);
       }
       for(int i=0;i<w;i++){
        ans.push_back(1);
       }
       for(int i=0;i<b;i++){
        ans.push_back(2);
       }
       for(int i=0;i<s;i++){
        nums[i]=ans[i];
       }
  }
