class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>ans(arr.size());
        vector<int>arr1(arr);
        sort(arr1.begin(),arr1.end());
        int rank =1;
        for(int i=0;i<arr1.size();i++){
            if(i>0 && arr1[i]>arr1[i-1])rank++;
            mp[arr1[i]]=rank;
        }
        for(int i=0;i<arr.size();i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};
