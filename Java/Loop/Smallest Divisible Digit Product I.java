class Solution {
    int check(int n){
        int pro=1;
        while(n!=0){
            pro*=n%10;
            n/=10;
        }
        return pro;
    }
    public int smallestNumber(int n, int t) {
        while(check(n)%t!=0){
            n++;
        }
        return n;
    }
}
