class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return false;
        int firstIndiff=-1;int diffcnt=0;
        if(s==goal){
            set<char>st(s.begin(),s.end());
            return st.size()<s.size();
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                diffcnt++;
                if(diffcnt==1)firstIndiff=i;
                else{
                    swap(s[i],s[firstIndiff]);
                    break;
                }
            }
        }
        return s==goal;
    }
};
