class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vec;
        for(auto num:nums){
            vec.push_back(to_string(num));
        }
        sort(vec.begin(),vec.end(),[](string &a,string &b){
            return a+b>b+a;
        });
        if(vec[0]=="0")return "0";
        string ans;
        for(auto i:vec){
            ans+=i;
        }
        return ans;
    }
};
