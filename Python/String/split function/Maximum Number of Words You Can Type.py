class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        cnt=0
        broken=set(brokenLetters)
        for word in text.split():
            ok =True      # Assume each word is valid (ok = True).

            # Check every character of the word: If a character exists in the broken set → the word cannot be typed (ok = False) → stop checking further.
            for ch in word:
                if ch in broken:
                    ok=False
                    break
            if ok:    # If ok remains True, it means no broken letters were found → increment counter.
                cnt+=1
        return cnt
        




