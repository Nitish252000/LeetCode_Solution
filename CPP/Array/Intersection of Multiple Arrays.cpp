class Solution {
public:
    vector<int> helper(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1= nums1.size();
        int n2= nums2.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
    vector<int> intersection(vector<vector<int>>& nums) {
        if(nums.size()==1){
            sort(nums[0].begin(),nums[0].end());
            return nums[0];
        } 
        vector<int>out;
        out=helper(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            out=helper(out,nums[i]);
        }
        sort(out.begin(),out.end());
        return out;
    }
};
