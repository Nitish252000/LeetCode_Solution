class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        //--- Kadane's algorithm --- this will not work here, bcz When we start
        //from index i, we keep jumping 0->k->2k-> ... until we go out of bounds.
        // Goal :: is to Find the maximum total energy possible if you can start from any index.
        // This code only explores one path:starting from i = 0, then 0 → k → 2k → …
        // That is correct for one starting index.

        /*int maxiE=0;
        int currE=0;
        for(int i=0;i<energy.size();i=i+k){
            currE=max(energy[i],currE+energy[i]);
            maxiE=max(maxiE,currE);
        }
        return maxiE;*/
        // ==> but we must try every possible starting index

        int n=energy.size();
        vector<int>dp(n,0);  // dp[i] = maximum energy obtainable starting from index i
        int ans=INT_MIN;
        for(int i=n-1;i>=0;i--){
            dp[i] = energy[i];             // always include your own energy first
            if(i+k<n)
            dp[i]+=dp[i+k];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
