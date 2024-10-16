class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans="";
        while(!pq.empty()){
            pair<char,int>p = pq.top();
            int cnt = p.first;
            char ch = p.second;
            pq.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==ch && ans[ans.size()-2]==ch){
                if(pq.empty())break;
                pair<int,char>sec = pq.top();
                pq.pop();
                ans+=sec.second;
                if(sec.first-1>0){
                    pq.push({sec.first-1,sec.second});
                }
            }
            else{
                cnt--;
                ans+=ch;
            }
            if (cnt>0){
                pq.push({cnt,ch});
            }
        }
        return ans;
    }
};
