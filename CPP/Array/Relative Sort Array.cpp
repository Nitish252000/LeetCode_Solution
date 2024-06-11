vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans,rem;
        unordered_map<int,int>mp;
        for(auto i:arr1){
            mp[i]++;
        }
        for(auto i:arr2){
            if(mp.find(i)!=mp.end()){
               auto it=mp.find(i);
               int n=it->second;
                for(int j=0;j<n;j++){
                    ans.push_back(i);
                }
                mp.erase(i);
            }
        }
        for(auto i:arr1){
            if(mp.find(i)!=mp.end()){ 
               int n=mp[i];
                for(int j=0;j<n;j++){
                    rem.push_back(i);
                }
                mp.erase(i);
            }
        }
        sort(rem.begin(),rem.end());
        // Append the sorted remaining elements to the result
        ans.insert(ans.end(), rem.begin(), rem.end());
        return ans;
    }
