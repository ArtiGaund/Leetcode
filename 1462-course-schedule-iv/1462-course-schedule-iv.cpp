class Solution {
public:
    void dfs(int src,vector<int> &vis,vector<int> adj[],vector<vector<bool>> &ispre,int node)
    {
        vis[node]=1;
        ispre[src][node]=1;
        for(auto it:adj[node])
            if(!vis[it])
                dfs(src,vis,adj,ispre,it);
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<vector<bool>> ispre(n,vector<bool>(n,0));
        for(auto p:pre)
        {
            adj[p[0]].push_back(p[1]);
            ispre[p[0]][p[1]]=1;
        }
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            dfs(i,vis,adj,ispre,i);
        }
        vector<bool> res;
        for(auto q:queries)
            res.push_back(ispre[q[0]][q[1]]);
        return res;
    }
};