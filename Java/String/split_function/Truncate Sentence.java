class Solution {
    public String truncateSentence(String s, int k) {
        // int word_cnt=0;
        String[] str=s.split(" ");
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < k; i++) {
            ans.append(str[i]).append(" ");
        }
        return ans.toString().trim();
    }
}
