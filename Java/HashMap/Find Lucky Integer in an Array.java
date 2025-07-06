class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i : arr) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        int maxi = -1;
        for (Integer i : mp.keySet()) {
            if (mp.get(i) == i)
                maxi = Math.max(maxi, i);
        }
        return maxi;
    }
}
