class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=accumulate(nums.begin(),nums.end(),0.0);
        priority_queue<double>pq;
        for(auto i:nums){
            pq.push((double)i);
        }
        double half = sum/2.0;
        int total_oper=0;
        double curr_sum=sum;
        while(curr_sum>half){
            double x=pq.top();
            pq.pop();
            double reduced=x/2.0;
            pq.push(reduced);
            curr_sum-=reduced;
            total_oper++;
        }
        return total_oper;
    }
};
