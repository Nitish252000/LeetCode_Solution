class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        HashMap<Integer, Pair> mp = new HashMap<>();
        int k = indices.length;
        for (int i = 0; i < k; i++) {
            int idx = indices[i];
            String src = sources[i];
            String targ = targets[i];

            if (idx + src.length() <= s.length() && s.substring(idx, idx + src.length()).equals(src)) {
                mp.put(idx, new Pair(src, targ));
            }
        }
        StringBuilder ans = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            if (mp.containsKey(i)) {
                Pair p = mp.get(i);
                ans.append(p.target); // append target
                i += p.source.length(); // skip source length
            } else {
                ans.append(s.charAt(i));
                i++;
            }
        }
        return ans.toString();
    }

    static class Pair {
        String source;
        String target;

        Pair(String s, String t) {
            source = s;
            target = t;
        }
    }
}
