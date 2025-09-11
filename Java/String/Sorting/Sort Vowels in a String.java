class Solution {
    boolean isVowel(char ch) {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    public String sortVowels(String s) {
        ArrayList<Character> temp = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (isVowel(c))
                temp.add(c);
        }

        Collections.sort(temp);

        int j = 0;
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                ans.append(temp.get(j));
                j++;
            } else {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
