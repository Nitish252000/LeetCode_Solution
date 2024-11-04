class Solution {
public:
    string compressedString(string word) {
        string comp;
        int i=0;
        int n =word.size();
        while(i<n){
            int cnt =0;
            char c=word[i];
            while (i<n && c==word[i] && cnt<9){
                //if(c==word[i]){
                    cnt++;
                //}
                i++;
            }
            comp+=to_string(cnt)+c;
        }
        return comp;
    }
};
