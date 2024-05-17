void sortColors(vector<int>& nums) {
        vector<int>ans;
        int nz = 0, no = 0;
        int nt=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]==0)nz++;
            else if(nums[i]==1)no++;
            else nt++;
        }
        for(int i=0;i<nz;i++){
            ans.push_back(0);
        }
        for(int i=0;i<no;i++){
            ans.push_back(1);
        }
        for(int i=0;i<nt;i++){
            ans.push_back(2);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=ans[i];
        }
}
