class Solution {
    public boolean divideArray(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        for (int i : mp.keySet()) {
            if (mp.get(i) % 2 == 1) {
                return false;
            }
        }
        return true;
    }
}
