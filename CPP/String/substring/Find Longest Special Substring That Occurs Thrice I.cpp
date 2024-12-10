class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i++){
            string curr;
            for(int j=i;j<s.size();j++){
                if(curr.empty() || curr.back()==s[j]){
                    curr.push_back(s[j]);
                    mp[curr]++;
                }else{
                    break;
                }
            }
        }
        int ans =0;
        for(auto i:mp){
            string str=i.first;
            if(i.second>=3){
                if(str.size()>ans)ans=str.size();
            }
        }
        if (ans==0)return -1;
        return ans;
    }
};
