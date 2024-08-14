class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
    //-----Time Limit Exceeded- 16/19 testcases passed------
        /*priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                pq.push(abs(nums[i]-nums[j]));
            }
        }
        int n=k-1;
        while(n--){
            pq.pop();
        }
        return pq.top();*/ 
    //-------Sorting + Sliding Window Approach----------
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int start=0;
        int end= nums[n-1]-nums[0];
        while(start<end){
            int mid = start+(end-start)/2;
            //count pairs with distance <= mid
            int count = pairWithMaxDistance(nums,mid);
            if(count<k){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return start;
    }

    int pairWithMaxDistance(vector<int>&nums, int maxdis){
       int count = 0;
       int n = nums.size() ;
       int left =0;
       for(int right = 0;right<n;right++){
        while(nums[right]-nums[left]>maxdis){
            left++;
        }
        count+=right-left;
       }
       return count;
    }
};
