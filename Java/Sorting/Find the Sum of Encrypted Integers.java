class Solution {
    private int encrypt(int num){
        String str=Integer.toString(num);
        int n=str.length();
        char[] arr=str.toCharArray();
        Arrays.sort(arr);
        String res="";
        for(int i=0;i<n;i++){
            res+=arr[arr.length-1];
        }
        return Integer.parseInt(res);
    }
    public int sumOfEncryptedInt(int[] nums) {
        int ans=0;
        for(int i=0;i<nums.length;i++){
            ans+=encrypt(nums[i]);
        }
        return ans;
    }
}
