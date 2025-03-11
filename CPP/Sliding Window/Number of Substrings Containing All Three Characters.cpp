class Solution {
public:
    int numberOfSubstrings(string s) {
        //----------Will give TLE--------
        /*int cnt=0;
        for(int i=0;i<s.size();i++){
            set<char>st;
            for(int j=i;j<s.size();j++){
                st.insert(s[j]);
                if(st.size()==3)cnt++;
            }
        }
        return cnt;*/
        int left=0, right=0;
        int cnt=0;
        vector<int>fq(3,0);
        for(right=0;right<s.size();right++){
            char ch=s[right];
            fq[ch-'a']++;
            while (fq[0]>0 && fq[1]>0 && fq[2]>0){
                cnt+=s.size()-right;

                fq[s[left]-'a']--;
                left++;
            }
        }
        return cnt;
    }
};
