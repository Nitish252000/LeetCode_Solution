class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans=[]
      #Slicing: Specify the start index and the end index, separated by a colon, to return a part of the string
        ans.append(s[:spaces[0]])
        for i in range(1,len(spaces)):
            ans.append(s[spaces[i-1]:spaces[i]])
        n = len(s)
        ss=len(spaces)
        ans.append(s[spaces[-1]:])
        return ' '.join(ans)
        
