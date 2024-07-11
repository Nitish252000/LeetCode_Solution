class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == ')') {
                string temp;
                // Pop characters until we find '('
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                // Pop the '(' from the stack
                if (st.top() == '(')
                    st.pop();
                // Push the reversed substring back onto the stack
                for (auto i : temp) {
                    st.push(i);
                }
            } else {
                // Push current character onto the stack
                st.push(c);
            }
        }
        // Collect the result from the stack
        string result;
        while (!st.empty()) {
            result = st.top()+result;
            st.pop();
        }
        return result;
    }
};
