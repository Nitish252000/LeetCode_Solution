vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto i : words) {
            mp[i]++;
        }
        auto compare = [&](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)>pq(compare);
        
        for (auto i : mp) {
            pq.push({i.second, i.first});
        }
        vector<string> ans;
        int cnt = 0;
        while (!pq.empty() && k > 0) {
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
            k--;
        }
        return ans;
    }
