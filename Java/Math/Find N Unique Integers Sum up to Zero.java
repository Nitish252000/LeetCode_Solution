class Solution {
    public int[] sumZero(int n) {
        // ArrayList<Integer> ans = new ArrayList<Integer>();
        int[] ans = new int[n];
        int index = 0;
        for (int i = 1; i <= n / 2; i++) {
            ans[index++] = i;
            ans[index++] = -i;
        }
        if (n % 2 == 1)
            ans[index] = 0;
        return ans;
    }
}
