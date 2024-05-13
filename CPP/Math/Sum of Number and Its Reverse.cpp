 bool sumOfNumberAndReverse(int num) {
        if(num==0)return true;
        for(int i=num/2;i<num;i++){
            string str = to_string(i);
            reverse(str.begin(),str.end());
            int res = stoi(str);
            if(i+res== num)return true;
        }
        return false;
 }
