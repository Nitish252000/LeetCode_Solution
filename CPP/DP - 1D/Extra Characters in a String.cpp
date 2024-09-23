class Solution {
public:
    int helper(int start,string &s, unordered_map<int,int>&mp,unordered_set<string> &st){
        int n = s.size();
        if(start==s.size())return 0;

        // check if the result is already computed
        if(mp.find(start)!=mp.end())return mp[start];
        int minextr= n-start;  //Initialize to maximum extra characters (if no valid words found)
        //Try every possible substring at index 'i'
        for(int j=start;j<s.size();j++){
            string sub = s.substr(start,j-start+1);
            if(st.find(sub)!=st.end()){
                int rem =helper(j+1,s,mp,st);
                minextr = min(minextr,rem);
            }
            else{
                int extr=j-start+1; //length of the substring
                int rem = helper(j+1,s,mp,st);
                minextr = min(minextr,extr+rem);
            }
            mp[start]=minextr;
        }
        return minextr;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());  // Convert dictionary to a hash set for fast lookup
        unordered_map<int,int>mp; //memoisation map
        //helper function
        return helper(0,s,mp,st);
    }
};
