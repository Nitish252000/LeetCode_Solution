class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        ans=[]
        folder.sort()
        ans.append(folder[0])
        str=folder[0]
        i=1
        while i<len(folder):
            if folder[i].find(str+'/')!=0:
                ans.append(folder[i])
                str=folder[i]
            i+=1
        return ans
        
# str.find():
# Returns the index of the first occurrence of the specified substring.
# If the substring is not found, it returns -1.
# Optional parameters: start and end indices to specify the search range.
# Example: my_string.find('substring', 10, 20) searches for ‘substring’ between indices 10 and 20.
