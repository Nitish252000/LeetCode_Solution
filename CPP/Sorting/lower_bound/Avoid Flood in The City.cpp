class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n =rains.size();
        vector<int>ans(n,1);
        unordered_map<int,int>full; // lake -> last rain day
        set<int>dry;    // store indices when rains[i]=0 (dry day)

        for(int i=0;i<n;i++){
            if(rains[i]==0){
                dry.insert(i);   //store the index for drying later
            }
            else{
                int lake =rains[i];
                ans[i]=-1;  // raining on that day
                if(full.count(lake)){
                    int lastRain=full[lake];

                    //find: dry day after last rain
                    auto it=dry.lower_bound(lastRain);
                    if (it == dry.end()) {
                        return {}; // no dry day available -> flood unavoidable
                    }
                    int dryDay = *it;
                    ans[dryDay] = lake; // dry this lake
                    dry.erase(it);  // remove used dry day
                }
                full[lake]=i;
            }
        }
        return ans;
    }
};
