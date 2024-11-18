class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n =sentence.size();
        bool ans = true;
        for(int i=0;i<n;i++){
            if(sentence[i]==' ' && i!=n-1){
                if(sentence[i-1]!=sentence[i+1])ans=false;
            }
            if (i==n-1){
                if(sentence[i]!=sentence[0])ans=false;
            }
        }
        return ans;
    }
};
