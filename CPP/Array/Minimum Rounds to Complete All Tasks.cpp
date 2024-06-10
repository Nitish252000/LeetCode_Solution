int minimumRounds(vector<int>& tasks) {
        int cnt =0;
        unordered_map<int,int>mp;
        for(auto i:tasks){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second==1){
                return -1;
            }
            else if(i.second%3==0){
                cnt+=i.second/3;
            }else{
                cnt+=i.second/3+1;
            }
        }
        return cnt;
    }
