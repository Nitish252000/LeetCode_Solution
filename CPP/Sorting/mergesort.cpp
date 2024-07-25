class Solution {
public:
    void merge(vector<int>&nums, int start, int mid, int end){
        vector<int>store(end-start+1,0);
        int k=0;
        if(start>=end)return;
        int left = start, right= mid+1;
        while(left<= mid && right<=end){
            if(nums[left]<nums[right]){
                store[k]=nums[left];
                k++;left++;
            }
            else{
                store[k]=nums[right];
                k++;
                right++;
            }
        }
        while(left<=mid){
            store[k]=nums[left];
            k++;left++;
        }
        while(right<=end){
            store[k]=nums[right];k++;right++;
        }
        for(int i=0;i<store.size();i++){
            nums[i+start]=store[i];
        }
    }
    void mergeSort(vector<int>&nums,int start, int end){
        if(start>=end)return;
        int mid = start+(end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
