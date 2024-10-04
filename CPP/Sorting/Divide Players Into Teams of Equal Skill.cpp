class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n =skill.size();
        sort(skill.begin(),skill.end());
        long long chemistry=0;
        int totalSkill = skill[0]+skill[n-1];
        for(int i=0;i<n/2;i++){
            int currSkill = skill[i]+skill[n-i-1];
            if(totalSkill!=currSkill){
                return -1;
            }
            chemistry+=skill[i]*skill[n-i-1];
        }
        return chemistry;
    }
};
