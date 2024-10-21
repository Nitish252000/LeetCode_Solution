class Solution {
public:
    int backtrack(string &s, int start, unordered_set<string>&uniqueSubstrings){
        // Base case: if we've reached the end, no more splits can be made
        if(start==s.size()){
            return 0;
        }
        int maxSplits = 0;
        //Try all possible substrings starting from 'start'
        for(int i=start;i<s.size();i++){
              string currentSubstring = s.substr(start, i - start + 1);

            // Only proceed if this substring hasn't been used before
            if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                uniqueSubstrings.insert(currentSubstring);  // Add the current substring
                int splits = 1 + backtrack(s, i + 1, uniqueSubstrings);  // Continue splitting the remaining part
                maxSplits = max(maxSplits, splits);  // Update the maximum splits
                uniqueSubstrings.erase(currentSubstring);  // Backtrack by removing the current substring
            }
        }
        return maxSplits;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>unique;
        return backtrack(s,0,unique);
    }
};
