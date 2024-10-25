class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        string str= folder[0];
        for(int i=1;i<folder.size();i++){
            if(folder[i].find(str+'/')!=0){
                ans.push_back(folder[i]);
                str=folder[i];
            }
        }
        return ans;
    }
};


// In C++, the find method is a part of the std::string class and is used to search for a specified substring or character within a string. It returns the index of the first occurrence of the specified substring or character if found, and std::string::npos if not found

