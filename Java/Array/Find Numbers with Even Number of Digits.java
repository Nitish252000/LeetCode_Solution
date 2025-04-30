class Solution {
    boolean check(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt++;
            num /= 10;
        }
        if (cnt % 2 == 0)
            return true;
        return false;
    }

    public int findNumbers(int[] nums) {
        int cnt = 0;
        for (int num : nums) {
            if (check(num))
                cnt++;
        }
        return cnt;
    }
}
