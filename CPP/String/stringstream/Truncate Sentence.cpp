class Solution {
public:
    string truncateSentence(string s, int k) {
        // string ans;
        // stringstream ss(s);
        // string word;
        // while (ss >> word && k != 0) {
        //     ans += word+" ";
        //     k--;
        // }
        // ans.pop_back();
        // return ans;

        // Method 2: without any in-built function
        string ans;
        int word_cnt=0;
        for(auto ch:s){
            if(ch==' '){
                word_cnt++;
                if(word_cnt==k){
                    break;
                }
            }
            ans+=ch;
        }
        return ans;
    }
};
