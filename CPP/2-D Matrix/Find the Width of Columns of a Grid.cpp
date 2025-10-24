class Solution {
public:
    int helper(int num){
        int n=abs(num);
        int cnt=0;
        if(n==0)return 1;
        while(n!=0){
            cnt++;
            n/=10;
        }
        return num<0?cnt+1:cnt;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>ans;
        int rz=grid.size();
        int cz=grid[0].size();

        for(int j=0;j<cz;j++){  //  Iterate over columns
            int maxi=0;
            for(int i=0;i<rz;i++){  // Iterate over rows
                int num=grid[i][j];
                maxi=max(maxi,helper(num));
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
