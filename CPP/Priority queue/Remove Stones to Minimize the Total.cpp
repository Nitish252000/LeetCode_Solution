class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto i:piles){
            pq.push(i);
        }
        int stones=0;
        while(k>0){
            k--;
            int np=pq.top();
            pq.pop();
            int s=np-floor(np/2.0);
            pq.push(s);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
