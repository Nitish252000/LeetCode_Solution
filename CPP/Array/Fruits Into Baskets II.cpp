class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        for (auto fruit : fruits) {
            bool couldNotPlace=true;
            for(int i = 0; i < baskets.size(); i++){
                if(baskets[i]>=fruit){
                    baskets[i]=0;
                    couldNotPlace=false;
                    break;
                }
            }
            if (couldNotPlace)unplaced++;
        }
        return unplaced;
    }
};
