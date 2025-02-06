class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
      //----------wrong logic-----------
        // vector<pair<int,int>>vec;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(i!=j){
        //             vec.push_back({nums[i],nums[j]});
        //         }
        //     }
        // }
        // int cnt=0;
        // for(int i=0;i<vec.size();i++){
        //     int prod=vec[i].first*vec[i].second;
        //     for(int j=0;j<vec.size();j++){
        //         if(i!=j){
        //             int curr=vec[j].first*vec[j].second;
        //             if(curr==prod)cnt++;
        //         }
        //     }
        // }
        // return cnt;
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int product=nums[i]*nums[j];
                cnt+=mp[product]*8;
                mp[product]++;
            }
        }
        return cnt;
    }
};
