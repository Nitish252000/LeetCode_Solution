class Solution {
public:
    string reorderSpaces(string text) {
        int space_cnt = 0;
        // Count spaces
        for (auto ch : text) {
            if (ch == ' ')
                space_cnt++;
        }
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        int word_cnt = words.size();
        if (word_cnt==1)return words[0]+string(space_cnt,' ');
        int space_between = space_cnt / (word_cnt - 1);
        int rem_space = space_cnt % (word_cnt - 1);

        string ans;
        int cnt = 0;
        for (int i = 0; i < word_cnt; i++) {
            ans += words[i];
            if (cnt != word_cnt-1) {
                ans += string(space_between, ' ');
                cnt++;
            }
        }
        return ans + string(rem_space, ' ');
    }
};
