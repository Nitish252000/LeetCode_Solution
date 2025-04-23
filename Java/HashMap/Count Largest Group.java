class Solution {
    public int countLargestGroup(int n) {
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        int maxValue = 0;
        for (int i = 1; i <= n; i++) {
            int key = 0, num = i;
            while (num != 0) {
                key += num % 10;
                num = num / 10;
            }
            mp.put(key, mp.getOrDefault(key, 0) + 1);
            maxValue = Math.max(maxValue, mp.get(key));
        }
        int cnt = 0;
        for (int i : mp.keySet()) {
            if (mp.get(i) == maxValue)
                cnt++;
        }
        return cnt;
    }
}
