class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (auto num : nums) {
            st.push_back(num);
            while (st.size() > 1) {
                int a = st[st.size() - 1];
                int b = st[st.size() - 2];
                int g = gcd(a, b);
                if (g > 1) {
                    st.pop_back();
                    st.pop_back();
                    long long lcm = (1LL * a * b) / g;
                    st.push_back((int)lcm);
                } else {
                    break;
                }
            }
        }
        return st;
    }
};
