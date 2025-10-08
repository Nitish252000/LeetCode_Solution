class Solution {
    // Custom lowerBound: first index with value >= target
    private int lowerBound(int[] arr,long need){
        int start=0;
        int end=arr.length;
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid]<need){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return start;
    }
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n=spells.length;
        int[] pairs=new int[n];
        Arrays.sort(potions);
        int i=0;
        for(int spell:spells){
            long need=(success + spell - 1) / spell;      //Math.ceil(success/spell);
            int idx=lowerBound(potions,need);
            pairs[i]=potions.length-idx;
            i++;
        }
        return pairs;
    }
}
