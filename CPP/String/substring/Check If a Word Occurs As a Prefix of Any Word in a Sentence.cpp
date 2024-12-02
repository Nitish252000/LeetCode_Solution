class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream s(sentence);
        string word;
        int ind=0;
        while(s>>word){
            ind++;
            if(word.substr(0,searchWord.size())==searchWord){
                return ind;
            }
        }
        return -1;
    }
};
