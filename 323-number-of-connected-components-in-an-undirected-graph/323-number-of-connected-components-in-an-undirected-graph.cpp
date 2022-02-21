class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
       for(auto e:edges)
       {
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
       }
        vector<bool> vis(n+1,false);
        int component=0;
        for(int i=0;i<=n;i++)
        {
            if(!vis[i])
            {
                component+=bfs(i,adj,vis);
            }
        }
        return component-1;
    }
    int bfs(int src,vector<int> adj[],vector<bool> &vis)
    {
        if(vis[src]) return 0;
        vis[src]=true;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:adj[u])
            {
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return 1;
    }
};