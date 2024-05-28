int equalSubstring(string s, string t, int maxCost) {
  //-------This approach will pass all testcases, but took too long.----------
        /*int n = s.length();
        int maxLength = 0;
        for(int start = 0; start < n; start++){
            int currCost = 0;
            for(int end = start; end < n; end++){
                currCost+= abs(s[end]-t[end]);
                if(currCost<=maxCost)maxLength = max(maxLength, end-start+1);
                else
                break;
            }
        }
        return maxLength;*/

//-----------------Sliding window Approach---------------------
        int start = 0, currCost = 0;
        int maxLength = 0;
        int n = s.size();
        for (int end = 0; end < n; end++){
          // Calculate the cost of the current character transformation
            currCost += abs(s[end]-t[end]);
          // If current cost exceeds maxCost, shrink the window from the left
            while(currCost > maxCost){
                currCost-=abs(s[start]-t[start]);
                start++;
            }
          // Update the maximum length of the valid window
            maxLength = max (maxLength, end-start+1);
        }
        return maxLength;
}
