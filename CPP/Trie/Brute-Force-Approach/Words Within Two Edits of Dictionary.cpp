class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size();

        for (auto& q : queries) {
            for (auto& d : dictionary) {
                int cnt_diff = 0;
                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i])
                        cnt_diff++;
                }
                if (cnt_diff <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};
