class Solution {
public:
    void bfs(int node,vector<int> adj[],vector<int> &vis)
    {
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(auto it:adj[cur])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
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
                bfs(i,adj,vis);
            }
        }
        return connected;
    }
};