class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& skills, vector<vector<string>>& people) {
        int n=people.size(),m=skills.size();
        unordered_map<string,int> skillId;
        for(int i=0;i<m;i++) skillId[skills[i]]=i;
        vector<int> skillsMaskOfPerson(n);
        for(int i=0;i<n;i++)
            for(string s:people[i])
                skillsMaskOfPerson[i] |= 1<<skillId[s];
        vector<long long> dp(1<<m,(1LL<<n)-1);
        dp[0]=0;
        for(int mask=1;mask<(1<<m);mask++)
        {
            for(int i=0;i<n;i++)
            {
                int smaller=mask & ~skillsMaskOfPerson[i];
                if(smaller!=mask)
                {
                    long long personMask=dp[smaller] | (1LL<<i);
                    if(__builtin_popcountll(personMask)<__builtin_popcountll(dp[mask]))
                        dp[mask]=personMask;
                }
            }
        }
        long long resMask=dp[(1<<m)-1];
        vector<int> res;
        for(int i=0;i<n;i++)
            if((resMask>>i)&1) res.push_back(i);
        return res;
    }
};