class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        cnt = 0
        for word in words:
            # Use slicing (s[:len(word)]) to get the substring of s that matches the length of word
            if s[:len(word)]==word:
                cnt+=1
        return cnt
