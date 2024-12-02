class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        ind =1
        # Split the sentence into words
        words = sentence.split()
        for word in words:
            # Check if the searchWord is a prefix of the word
            if(word.startswith(searchWord)):
                return ind
            ind+=1
        return -1
