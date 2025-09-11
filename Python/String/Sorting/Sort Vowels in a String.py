class Solution(object):
    def isVowel(self,ch):
        return ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U' or ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'
    
    def sortVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        temp=[]
        for ch in s:
            if self.isVowel(ch):
                temp.append(ch)
        temp.sort()
        ans=[]
        j=0
        for i in s:
            if self.isVowel(i):
                ans.append(temp[j])
                j+=1
            else:
                ans.append(i)
        return "".join(ans)
