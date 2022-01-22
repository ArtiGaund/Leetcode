class Solution {
public:
    bool winnerSquareGame(int n) {
        unordered_map<int,bool> mp;
        mp[0]=false;
        return dfs(mp,n);
    }
    bool dfs(unordered_map<int,bool> &mp,int n)
    {
        if(mp.find(n)!=mp.end()) return mp[n];
        int sq=(int)sqrt(n);
        for(int i=1;i<=sq;i++)
        {
            if(!dfs(mp,n-i*i))
            {
                mp[n]=true;
                return true;
            }
        }
        mp[n]=false;
        return false;
    }
};