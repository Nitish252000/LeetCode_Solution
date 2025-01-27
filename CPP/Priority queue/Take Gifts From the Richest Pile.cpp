class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto i:gifts){
            pq.push(i);
        }
        while(k!=0){
            int t = pq.top();
            pq.pop();
            pq.push(floor(sqrt(t)));
            k--;
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();pq.pop();
        }
        return sum;
    }
};
