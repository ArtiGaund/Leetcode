class Solution {
public:
    int bfs(int n,vector<pair<int,int>> adj[])
    {
        vector<bool> vis(n+1,0);
        queue<int> q;
        int res=INT_MAX;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto e:adj[node])
            {
                res=min(res,e.second);
                if(!vis[e.first])
                {
                    vis[e.first]=1;
                    q.push(e.first);
                }
            }
        }
        return res;
    }
        int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(auto r:roads)
        {
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        return bfs(n,adj);
    }
};