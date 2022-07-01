class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<vector<int>> &stones)
    {
        vis[node]=1;
        int x=stones[node][0],y=stones[node][1];
        for(int i=0;i<stones.size();i++)
        {
            if((stones[i][0]==x or stones[i][1]==y) and !vis[i])
                dfs(i,vis,stones);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int group=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                group++;
                dfs(i,vis,stones);
            }
        }
        return n-group;
    }
};