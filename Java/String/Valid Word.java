class Solution {
    public boolean isValid(String word) {
        if(word.length()<3)return false;
        boolean is_vowel=false;
        boolean is_consonant=false;
        for(char ch:word.toCharArray()){
            if(!Character.isLetterOrDigit(ch))return false;
            if(Character.isLetter(ch)){
                ch=Character.toLowerCase(ch);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')is_vowel=true;
                else
                    is_consonant=true;
            }
        }
        return is_vowel&&is_consonant;
    }
}
