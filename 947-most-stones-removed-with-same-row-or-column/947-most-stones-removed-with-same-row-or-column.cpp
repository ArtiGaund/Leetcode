class Solution {
public:
    void dfs(vector<vector<int>> &stones,int pos,vector<bool> &vis)
    {
        int x=stones[pos][0],y=stones[pos][1];
        vis[pos]=1;
        for(int i=0;i<stones.size();i++)
        {
            if((stones[i][0]==x or stones[i][1]==y) and !vis[i])
                dfs(stones,i,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> vis(n,0);
        int group=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                group++;
                dfs(stones,i,vis);
            }
        }
        return n-group;
    }
};