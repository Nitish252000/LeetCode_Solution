class Solution:
    def check(self, s:str, index:int, words: List[str])->bool:
        i = 0
        while i<len(words):
            if i!=index and words[i].find(s) !=-1:
              return True
            i=i+1
        return False
    def stringMatching(self, words: List[str]) -> List[str]:
        li=list()
        i=0
        while i<len(words):
            if self.check(words[i],i,words):
                li.append(words[i])
            i=i+1
        return li
