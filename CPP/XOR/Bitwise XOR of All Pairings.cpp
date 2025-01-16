class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>nums3;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         nums3.push_back(nums1[i]^nums2[j]);
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<nums3.size();i++){
        //     ans=ans^nums3[i];
        // }
        // return ans;
        int len1=nums1.size();
        int len2=nums2.size();

        unordered_map<int,long>fq;
        for(int num:nums1){
            fq[num]+=len2;
        }
        for(int num:nums2){
            fq[num]+=len1;
        }
        int ans=0;
        for(auto [num,cnt]:fq){
            if(cnt%2==1){
                ans^=num;
            }
        }
        return ans;
    }
};
