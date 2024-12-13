class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>track(nums.size(), false);
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long score=0;
        while(!pq.empty()){
            auto [val,ind]=pq.top();
            pq.pop();
            if(track[ind])continue;
            score+=val;
            track[ind]=true;
            if(ind>0)track[ind-1]=true;
            if (ind<nums.size()-1)track[ind+1]=true;
        }
        return score;
    }
};
