int mySqrt(int x) {
        if (x==0)return 0;
        int start=1;
        int end = x;
        int ans; //for nearest
        while(start<=end){
            int mid = start+(end-start)/2;

            if(mid == x/mid)return mid;

            else if(mid > x/mid){
                end = mid-1;
            }
            else{
                start=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
