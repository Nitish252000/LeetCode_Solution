class Solution {
public:
    int check(int n){
        int product=1;
        while(n!=0){
            product*=n%10;
            n=n/10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(check(n)%t!=0){
            n++;
        }
        return n;
    }
};
