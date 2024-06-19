int helper(string st, int k , char ch){
        int cnt =0;
        int maxl = 0, left =0;
        for(int right =0;right<st.size();right++){
            if(st[right]!=ch)cnt++;
            while(cnt>k){
                if(st[left]!=ch)cnt--;
                left++;
            }
            maxl= max(maxl,right-left+1);
        }
        return maxl;
    }
    int maxConsecutiveAnswers(string key, int k) {
       return max(helper(key,k,'T'), helper(key,k,'F')) ;
    }
