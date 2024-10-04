class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int totalSkills=0;
        unordered_map<int,int> mp;
        for(int s:skill){
            totalSkills+=s;
            mp[s]=mp[s]+1;
        }
        if(totalSkills%(n/2)!=0){
            return -1;
        }
        int targetSkill=totalSkills/(n/2);
        long long totalChem=0;
        for(auto [skill,freq]:mp){
            int temp=targetSkill-skill;
            if(mp.find(temp)==mp.end() or freq!=mp[temp]) return -1;
            totalChem+=(long long)skill*(long long)temp*(long long)freq;
        }
        return totalChem/2;
    }
};