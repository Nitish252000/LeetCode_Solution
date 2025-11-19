class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1)
            return {};                    // If odd length : Impossible

        sort(changed.begin(), changed.end());
        unordered_map<int, int> fq;

        for (auto num : changed) {
            fq[num]++;
        }

        vector<int> original;
        for (auto org : changed) {
            if (fq[org] == 0)
                continue;
            if (fq[2 * org] == 0)                  
                return {};                 // No double exists

            fq[org]--;
            fq[2 * org]--;
            original.push_back(org);
        }
        return original;
    }
};
