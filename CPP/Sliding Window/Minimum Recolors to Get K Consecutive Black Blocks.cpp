int minimumRecolors(string blocks, int k) {
        int left = 0;
        int ans = INT_MAX;
        int cnt = 0;
        for (int right = 0; right < blocks.size(); right++) {
            if(blocks[right]=='W')cnt++;
            if(right-left+1==k){
                ans =min(ans, cnt);
                if(blocks[left]=='W')cnt--;
                left++;
            }
        }
        return ans;
    }
