class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int poppedInd=0;
        for(auto num:pushed){
            st.push(num);
            while(!st.empty() && popped[poppedInd]==st.top()){
                poppedInd++;
                st.pop();
            }
        }
        if(poppedInd==popped.size())return true;
        return false;
    }
};
