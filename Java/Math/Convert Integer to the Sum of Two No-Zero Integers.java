class Solution {
    boolean isContainZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) {
                return false;
            }
            n = n / 10;
        }
        return true;
    }

    public int[] getNoZeroIntegers(int n) {
        // int[] ans=new int[2]
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isContainZero(a) && isContainZero(b)) {
                return new int[]{a,b};
            }
        }
        return new int[0];
    }
}
