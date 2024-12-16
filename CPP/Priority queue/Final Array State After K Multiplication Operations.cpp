class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k!=0){
            auto [val,ind] = pq.top();
            pq.pop();
            pq.push({val*multiplier,ind});
            k--;
        }
        vector<int>ans(nums.size());
        while(!pq.empty()){
            auto [val,ind]=pq.top();
            pq.pop();
            ans[ind]=val;
        }
        return ans;
    }
};
