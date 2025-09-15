class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        int sz = brokenLetters.size();
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        stringstream ss(text);
        string word;
        while (ss >> word){
            bool ok =true;
            for(auto ch:word){
                if(broken.count(ch)){
                    ok=false;
                    break;
                }
            }
            if(ok)cnt++;
        }
        return cnt;
    }
};
