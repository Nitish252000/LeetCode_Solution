class Solution {
public:
    // // long long toDecimal(string str){
    // //     // int num  = stoi(str);
    // //     // int ans =0;
    // //     // int i=0;
    // //     // while(num!=0){
    // //     //     int digit =num%10;
    // //     //     ans+=pow(2,i)*digit;
    // //     //     num/=10;
    // //     //     i++;
    // //     // }
    // //     // return ans;
    // //     long long ans = 0;
    // //     for (char c : str) {
    // //         ans = ans * 2 + (c - '0');
    // //     }
    // //     return ans;
    // // }

    // long long toDecimal(string str){
    //     long long ans=0;
    //     for(auto c:str){
    //         ans=2*ans+(c-'0');
    //     }
    //     return ans;
    // }
    // string toBinary(int n){
    //     if (n == 0) return "0";

    //     string res;
    //     while(n!=0){
    //         int bit=n&1;
    //         n=n>>1;
    //         res=to_string(bit)+res;
    //     }
    //     return res;
    // }
    // string addBinary(string a, string b) {
    //     long long num1=toDecimal(a);
    //     long long num2=toDecimal(b);
    //     long long num = num1+num2;
    //     return toBinary(num);
    // }
    string addBinary(string a, string b) {
        int i=a.size()-1, j=b.size()-1;
        int carry = 0;
        string ans;
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
