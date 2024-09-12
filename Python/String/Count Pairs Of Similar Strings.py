class Solution:
    def similarPairs(self, words: List[str]) -> int:
        cnt =0
        for i in range(len(words)):
            st1 = set(words[i])
            for j in range(i+1,len(words)):
                st2=set(words[j])
                if st1==st2:
                    cnt+=1
        return cnt

        
