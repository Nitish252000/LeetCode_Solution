int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int cnt = 0;
        int i = 0;
        int j = 0;
        while (i < p.size()) {
            while (j < t.size() && p[i] > t[j]) {
                j++;
            }
            if (j<t.size() && p[i] <= t[j]) {
                cnt++;
                j++;
            }
            i++;
        }
        return cnt;
    }
