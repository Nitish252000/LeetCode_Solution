class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int curr = mp.size(); // Current distinct elements
        if (curr <= k)        // Already at most k distinct elements
            return 0;

        int to_del = curr - k; // number of character to delete fully

        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(),
             [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second < b.second;
        });

        int cnt =0;
        for(int i=0;i<to_del;i++){
            cnt+=vec[i].second;
        }
        return cnt;
    }
};
