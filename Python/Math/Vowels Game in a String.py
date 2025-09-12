class Solution(object):
    def doesAliceWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cnt=0
        for ch in s:
            if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u':
                cnt+=1
        return cnt>0
        
