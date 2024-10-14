class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int>pq;
        for(auto i:nums){
            pq.push(i);
        }
        for(int i=0;i<k;i++){
            int maxele=pq.top();
            score+=maxele;
            pq.pop();
            pq.push(ceil(maxele/3.0));
        }
        return score;
    }
};
