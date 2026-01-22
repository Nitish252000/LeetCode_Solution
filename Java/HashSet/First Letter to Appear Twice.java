class Solution {
    public char repeatedCharacter(String s) {
        Set<Character>seen = new HashSet<>();
        char[] str =s.toCharArray();
        for(char ch :str){
            if(seen.contains(ch))return ch;
            else seen.add(ch);
        }
        return ' ';
    }
}
