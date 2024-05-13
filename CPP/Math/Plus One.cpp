vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]=digits[i]+carry;
                return digits;
            }
            digits[i]=0;
            carry=1;
        }
        digits.insert(digits.begin(),1);
        return digits;
}
