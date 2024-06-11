 int minProcessingTime(vector<int>& pT, vector<int>& t) {
        sort(t.begin(),t.end());
        sort(pT.begin(),pT.end());
        int n=pT.size();
        int m= t.size();
        int ans =0;
        int k =m-1;
        for(int i=0;i<n;i++){
            int j=0;
            while(j<4){
                ans=max(ans,t[k]+pT[i]);
                j++;
                k--;
            }
        }
        return ans;
    }
