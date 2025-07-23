class Solution {
    private int helper(StringBuilder s, String remo, int points) {
        int score = 0;
        Stack<Character> st = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!st.isEmpty() && st.peek() == remo.charAt(0) && c == remo.charAt(1)) {
                st.pop();
                score += points;
            } else {
                st.push(c);
            }
        }

        // Build the remaining string
        StringBuilder remaining = new StringBuilder();
        while (!st.isEmpty()) {
            remaining.append(st.pop());
        }

        s.setLength(0);  // Clear original StringBuilder
        s.append(remaining.reverse());

        return score;
    }

    public int maximumGain(String s, int x, int y) {
        int points = 0;
        StringBuilder sb = new StringBuilder(s);

        if (x >= y) {
            points += helper(sb, "ab", x);
            points += helper(sb, "ba", y);
        } else {
            points += helper(sb, "ba", y);
            points += helper(sb, "ab", x);
        }

        return points;
    }
}
