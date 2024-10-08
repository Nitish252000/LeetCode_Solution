class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(auto i:nums){
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>sz){
            pq.pop();
        }
        return pq.top();
    }
};
