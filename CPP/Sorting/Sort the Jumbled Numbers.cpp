class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++){
            string st=to_string(nums[i]);
            string formed;
            for(int j=0;j<st.size();j++){
                formed+=to_string(mapping[st[j]-'0']);
            }
            int number=stoi(formed);
            // Push a pair consisting of mapped value and original value's index
            vec.push_back({number,i});
        }
        //sort the vector in non-decreasing order based on the first value
        sort(vec.begin(),vec.end()) ;
        vector<int>ans;
        for(auto i:vec){
            ans.push_back(nums[i.second]);
        }
        return ans;
    }
};
