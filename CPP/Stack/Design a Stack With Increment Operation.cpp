class CustomStack {
public:
    vector<int>st;
    int topIndex;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        topIndex=-1;
    }
    
    void push(int x) {
        if(topIndex<(int)(st.size()-1))    {
            topIndex++;
            st[topIndex]=x;
        }
    }
    
    int pop() {
        if(topIndex>=0){
            int poppedVal= st[topIndex];
            topIndex--;
            return poppedVal;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n = min(k,topIndex+1);
        for(int i=0;i<n;i++){
            st[i]=st[i]+val;
        }
    }
};
