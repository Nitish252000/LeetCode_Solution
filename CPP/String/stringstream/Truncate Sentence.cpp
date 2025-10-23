class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        stringstream ss(s);
        string word;
        while (ss >> word && k != 0) {
            ans += word+" ";
            k--;
        }
        ans.pop_back();
        return ans;
    }
};
