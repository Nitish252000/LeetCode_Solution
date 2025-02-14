class ProductOfNumbers {
private:
    vector<int>stream;
public:
    ProductOfNumbers() {
        vector<int>stream={};
    }
    
    void add(int num) {
       stream.push_back(num);
    }
    
    int getProduct(int k) {
        int n=stream.size();
        int pro=1;
        for(int i=n-1;i>=n-k;i--){
            if(stream[i]==0)return 0;
            pro*=stream[i];
        }
        return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
