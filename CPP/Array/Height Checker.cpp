 int heightChecker(vector<int>& heights) {
       vector<int> v=heights;
        int c=0;
        sort(v.begin(),v.end());
        int k=0;
        for(int i=0;i<heights.size();i++){
            if(v[k]!=heights[i])c++;
            k++;
        }
        return c; 
    }
