class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        if(s1.size()!=s2.size())return false;
        int i=0;
        int firstdiffIn=-1;
        for(i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt==1)firstdiffIn=i;
                else{
                    swap(s1[firstdiffIn],s1[i]);
                    break;
                }
            }   
        }
        return s1==s2;
    }
};
