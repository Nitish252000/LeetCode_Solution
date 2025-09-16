class Solution {
    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> st = new ArrayList<>();
        for (int num : nums) {
            st.add(num);
            while (st.size() > 1) {
                int a = st.get(st.size() - 1);
                int b = st.get(st.size() - 2);
                int g = gcd(a, b);
                if (g > 1) {
                    st.remove(st.size() - 1);  // remove last elemt
                    st.remove(st.size() - 1);
                    long lcm = (long) a * b / g;
                    st.add((int) lcm);
                } else {
                    break;
                }
            }
        }
        return st;
    }
}
