class Solution(object):
    def remsubstr(self, s, rem, points):
        score = 0
        st = []
        for i in s:
            if st and st[-1] == rem[0] and i == rem[1]:
                st.pop()
                score=score+points
            else:
                st.append(i)
        # Rebuild the remaining string from the stack
        remaining = ''.join(st)
        s=remaining
    
        return remaining, score
        
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        points = 0
    
        if x >= y:
            s, score = self.remsubstr(s, "ab", x)
            points += score
            s, score = self.remsubstr(s, "ba", y)
            points += score
        else:
            s, score = self.remsubstr(s, "ba", y)
            points += score
            s, score = self.remsubstr(s, "ab", x)
            points += score
    
        return points
