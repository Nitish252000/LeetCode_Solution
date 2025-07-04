class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int n=1;
        while(ss>>word){
            n=word.size();
        }
        return n;
    }
};
