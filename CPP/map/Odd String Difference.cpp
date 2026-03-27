class Solution {
public:
    // Method 1: 
    // vector<int> diff(string word) {
    //     vector<int> d_vec;
    //     for (int i = 0; i < word.size() - 1; i++) {
    //         d_vec.push_back(word[i + 1] - word[i]); // The ASCII values for lowercase letters 'a' to 'z' range from 97 to 122
    //     }
    //     return d_vec;
    // }
    // string oddString(vector<string>& words) {
    //     map<vector<int>, vector<string>> mp;
    //     for (auto word : words) {
    //         mp[diff(word)].push_back(word);
    //     }

    //     for (auto m : mp) {
    //         if (m.second.size() == 1) {
    //             return m.second[0];
    //         }
    //     }
    //     return "";
    // }

    // Method 2: 
    string diff(string word) {
        string d;
        for (int i = 0; i < word.size() - 1; i++) {
            d+=word[i + 1] - word[i]; // The ASCII values for lowercase letters 'a' to 'z' range from 97 to 122
        }
        return d;
    }
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string>> mp;
        for (auto word : words) {
            mp[diff(word)].push_back(word);
        }

        for (auto m : mp) {
            if (m.second.size() == 1) {
                return m.second[0];
            }
        }
        return "";
    }

};
