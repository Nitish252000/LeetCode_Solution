class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s)!=len(goal):return False
        if s==goal:
            st=set(s)
            return len(st)<len(s)
        # swap doea not exist in python 
        # firstIndexdiff=-1
        # totaldiff=0
        # for i in range(len(s)):
        #     if s[i]!=goal[i]:
        #         totaldiff+=1
        #         if totaldiff==1:firstIndexdiff=i
        #         else:
        #             swap(s[firstIndexdiff],s[i])
        #             break
        # return s==goal
        diff=[]
        for i in range(len(s)):
            if s[i]!=goal[i]:
                diff.append(i)
                if len(diff)>2:return False
        if len(diff)==2 and s[diff[0]]==goal[diff[1]] and s[diff[1]]==goal[diff[0]]:
            return True
        return False
