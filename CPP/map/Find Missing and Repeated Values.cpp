vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n=grid.size();
        int missing=-1,repeating=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            //if (mp[i]==0) missing = i;
            if(mp.count(i)==0) missing=i;
            if(mp[i]>1)repeating=i;
        }
        return {repeating,missing};
    }
