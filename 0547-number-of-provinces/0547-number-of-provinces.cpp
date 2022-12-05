class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size(),n=isConnected[0].size();
        vector<int> adj[m];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(m,0);
        int connected=0;
        for(int i=0;i<m;i++)
        {
            if(!vis[i])
            {
                connected++;
                dfs(i,adj,vis);
            }
        }
        return connected;
    }
};