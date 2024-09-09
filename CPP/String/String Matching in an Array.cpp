class Solution {
public:
    bool check(string s, int index,vector<string>words){
        for(int i=0;i<words.size();i++){
          //find() method in C++ returns the position of the first occurrence of the substring, but it returns std::string::npos if the substring is not found. You need to check if the result of find() is not equal to std::string::npos to determine if the substring exists in the other strings
            if(i!=index && words[i].find(s) !=string::npos){
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            if(check(words[i],i,words)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
