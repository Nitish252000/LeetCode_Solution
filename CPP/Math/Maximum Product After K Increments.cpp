int maximumProduct(vector<int>& nums, int k) {
        int MOD = 1000000007;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto i:nums){
            pq.push(i);
        }
        for(int i=0;i<k;i++){
            int t = pq.top();
            pq.pop();
            t=t+1;
            pq.push(t);
        }
        long long int ans = 1;
        while(!pq.empty()){
            ans=(ans*pq.top())%MOD;
            pq.pop();
        }
        return ans;
    }
