class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        /*
        // For every Person: we store the meeting time with Person met.
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        vector<int>knows(n,INT_MAX);
        knows[0]=0;
        knows[firstPerson]=0;

        // BFS from secret holders
        queue<pair<int, int>> q; // Queue for BFS: It will store (person , time of knowing the secret)
        q.emplace(0, 0);
        q.emplace(firstPerson, 0);
        
        while(!q.empty()){
            auto [person, time]=q.front();
            q.pop();
            for(auto [t,nextPerson]:graph[person]){
                if(t>=time && knows[nextPerson]>t){
                    knows[nextPerson]=t;
                    q.emplace(nextPerson,t);
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(knows[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
        */

        //--------------- Above Code is giving TLE --------


        
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto &m : meetings) {
            int x = m[0], y = m[1], t = m[2];
            graph[x].push_back({t, y});
            graph[y].push_back({t, x});
        }

        // sort adjacency lists to avoid unnecessary BFS exploration
        for (auto &p : graph) {
            sort(p.second.begin(), p.second.end());
        }

        vector<int> knows(n, INT_MAX);
        knows[0] = 0;
        knows[firstPerson] = 0;

        queue<pair<int,int>> q;
        q.push({0, 0});
        q.push({firstPerson, 0});

        while (!q.empty()) {
            auto [u, t] = q.front();
            q.pop();
            for (auto &[tm, v] : graph[u]) {
                if (tm >= t && knows[v] > tm) {
                    knows[v] = tm;
                    q.push({v, tm});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (knows[i] != INT_MAX)
                ans.push_back(i);
        }

        return ans;
    }
};
