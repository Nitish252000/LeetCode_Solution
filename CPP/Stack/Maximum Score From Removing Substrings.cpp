class Solution {
public:
    int removeSubstr(string& s, string rem, int points) {
        stack<char> st;
        int score = 0;
        for (auto i : s) {
            if (!st.empty() && st.top() == rem[0] && i == rem[1]) {
                st.pop();
                score += points;
            } else {
                st.push(i);
            }
        }
        // Collect the remaining characters
        string remaining;
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        s = remaining; // Update the original string with the remaining characters
        return score;
    }
    int maximumGain(string s, int x, int y) {
        // We prioritize removing the substring with the higher points first
        int points = 0;
        if (x >= y) {
            points += removeSubstr(s, "ab", x);
            points += removeSubstr(s, "ba", y);
        } else {
            points += removeSubstr(s, "ba", y);
            points += removeSubstr(s, "ab", x);
        }
        return points;
    }
};
