class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        st = set(allowed)
        cnt= 0
        for i in words:
            iscons = True
            for j in i:
                if j not in st:
                    iscons = False
                    break
            if iscons:
                cnt += 1
        return cnt
        
