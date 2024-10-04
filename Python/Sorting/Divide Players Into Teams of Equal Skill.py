class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        skill.sort()
        chemistry = 0
        totalSkill = skill[0]+skill[n-1]
        i = 0
        while i<n/2:
            currSkill = skill[i]+skill[n-1-i]
            if currSkill!=totalSkill:
                return -1
            chemistry+=skill[i]*skill[n-i-1]
            i+=1

        return chemistry


       
