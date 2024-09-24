class TrieNode {
public:
    TrieNode* children[10]; // digits are 0-9
    TrieNode() {
        for (int i = 0; i < 10; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& num) {
        TrieNode* node = root;
        for (char c : num) {
            int index = c - '0';  // convert char to corresponding digit
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
    }
    
    int searchLongestPrefix(string& num) {
        TrieNode* node = root;
        int commonPrefixLength = 0;
        for (char c : num) {
            int index = c - '0';
            if (node->children[index] != nullptr) {
                commonPrefixLength++;
                node = node->children[index];
            } else {
                break;
            }
        }
        return commonPrefixLength;
    }
};
class Solution {
public:
/**-------Time Limit Exceeded: 694 / 718 testcases passed-------------**/
    /*int check(int num1, int num2){
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        int n = min(s1.size(),s2.size());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        for(auto i:arr1){
            for(auto j:arr2){
                ans = max(ans,check(i,j));
            }
        }
        return ans;
    }*/
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
    
        // Convert arr1 numbers to strings and insert them into the Trie
        for (int num : arr1) {
            string numStr = to_string(num);
            trie.insert(numStr);
        }
        
        // Now find the longest common prefix for each number in arr2
        int longest = 0;
        for (int num : arr2) {
            string numStr = to_string(num);
            int commonPrefix = trie.searchLongestPrefix(numStr);
            longest = max(longest, commonPrefix);
        }
        
        return longest;
    }
};
