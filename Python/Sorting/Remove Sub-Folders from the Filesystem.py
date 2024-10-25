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
        
