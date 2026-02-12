class Solution {
    public int longestBalanced(String s) {
        int n = s.length();
        int lbs = 0;
        for (int i = 0; i < n; i++) {
            HashMap<Character, Integer> mp = new HashMap<>();
            for (int j = i; j < n; j++) {
                mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0) + 1);
                int cnt = mp.get(s.charAt(j));
                boolean flag = true;
                for (Character m : mp.keySet()) {
                    if (cnt != mp.get(m)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    lbs = Math.max(lbs, j - i + 1);
                }
            }
        }
        return lbs;
    }
}
