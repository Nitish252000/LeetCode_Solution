class Solution {
public:
    int minimumLength(string s) {
        // Count the frequency of each character in the String 
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        // Calculate: Number of Charcters to delete
        int delcnt=0;
        for(auto i:mp){
            // if frequency is odd: delete all except one
            if(i.second%2==1){
                delcnt+=i.second-1;
            }
            // if frequency is even : delete all except two
            else{
                delcnt+=i.second-2;
            }
        }
        return s.size()-delcnt;
    }
};
