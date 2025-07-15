class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        bool is_vowel=false;
        bool is_consonant=false;
        for(auto ch:word){
            if(!isalnum(ch))return false; // not a letter or digit
            if(isalpha(ch)){
                ch=tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')is_vowel=true;
                else
                    is_consonant=true;
            }
        }
        return is_vowel && is_consonant; 
    }
};
