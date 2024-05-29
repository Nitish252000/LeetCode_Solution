/*long long convertToDecimal(string &s){
        int n = s.size();
        int p=0;
        long long ans = 0;
        for(int i=n-1;i>=0;i--){
            int bit = s[i]-'0';
            ans=ans+pow(2,p)*bit;
            p++;
        }
        return ans;
    }
    int numSteps(string s) {
       long long num = convertToDecimal(s);
       int cnt = 0;
       while(num!=1){
        if(num%2==0)num=num/2;
        else num=num+1;
        cnt++;
       }
       return cnt;
    }*/
    int numSteps(string s) {
        int cnt = 0;
        while(s != "1"){
          if(s.back() =='0') {
            // If the current number is even, divide it by 2
            s.pop_back();  // Remove the last character (equivalent to dividing by 2)
          }
          else{
            // If the current number is odd, add 1
            int i = s.size()-1;
            while(i >=0 && s[i] == '1'){
                s[i] = '0';   // Handle the carry for adding 1
                i--;
            }
            if(i>=0){
                s[i] = '1';
            }
            else{
                // If all bits were '1', we need an extra bit at the start
                s = "1"+s;
            }
          }
          cnt++;
        }
        return cnt;
    }
