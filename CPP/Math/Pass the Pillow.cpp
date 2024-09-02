class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time/(n-1);
        int rem = time%(n-1);
        if(dir%2 == 0){
            return rem+1;
        }
        else{
            return n-rem;
        }
    }
};
