class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt =0;
        unordered_set<char>st;
        for(auto i:allowed){
            st.insert(i);
        }
        for(auto i:words){
            string curr =i;
            bool iscons = true;
            for(auto j:curr){
                if(st.find(j)==st.end()){
                    iscons =false;
                    break;
                }
            }
            if(iscons)cnt++;
        }
        return cnt;
    }
};
