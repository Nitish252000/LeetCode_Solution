class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pairs;
        // -------------- will give TLE : T.C = O(N*M) ----------------
        /*for(int i=0;i<spells.size();i++){
            int cnt=0;
            for(int j=0;j<potions.size();j++){
                long long product=1LL*spells[i]*potions[j];
                if(product>=success)cnt++;
            }
            pairs.push_back(cnt);
        }*/

        sort(potions.begin(),potions.end());
        for(auto spell:spells){
            // minimum potion value needed for success
            long long need = ceil((double)success/spell);

            // find first potion >= need
            auto it=lower_bound(potions.begin(),potions.end(),need);
            pairs.push_back(potions.end()-it);
        }
        return pairs;        
    }
};
