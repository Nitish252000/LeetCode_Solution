int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
       vector<pair<int,int>>job;
       int n = d.size();
       for(int i=0;i<n;i++){
        job.push_back({d[i],p[i]});
       }
      // Sort jobs by difficulty (and by profit if difficulties are the same)
       sort(job.begin(),job.end());
     // Sort workers by their abilities
       sort(w.begin(),w.end());
       int maxP=0;int totalP=0;
       int j=0;
       for(int i=0;i<w.size();i++){
        while(j<n && job[j].first<=w[i]){
            //if(job[j].first<=w[i]){
                maxP=max(maxP, job[j].second);
           // }
            j++;
        }
        totalP+=maxP;
       }
       return totalP;
    }
