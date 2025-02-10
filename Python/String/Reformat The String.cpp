class Solution {
public:
    string reformat(string s) {
        string digit, letter,ans;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]-'0'>=0 && s[i]-'0'<=9){
        //         digit+=s[i];
        //     }else{
        //         letter+=s[i];
        //     }
        // }

        // Separate digits and letters
        for (char c : s) {
            if (isdigit(c)) {
                digit += c;
            } else {
                letter += c;
            }
        }
        if (abs((int)letter.size()-(int)digit.size())>1)return ans;
        // Determine if digits should come first
        bool digitFirst=digit.size()>letter.size();
        int l=0;int d=0;

        while(l<letter.size() || d<digit.size()){
            if(digitFirst && d<digit.size())
            ans+=digit[d++];
            else ans+=letter[l++];
            digitFirst=!digitFirst; //Alternate
        }
        return ans;
    }
};
