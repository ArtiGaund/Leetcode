class Solution {
public:
    //DFS
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<vector<bool>> ispre(n,vector<bool>(n,false));
        for(auto p:pre)
        {
            adj[p[0]].push_back(p[1]);
            ispre[p[0]][p[1]]=true;
        }
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            dfs(i,adj,ispre,vis,i);
        }
        vector<bool> res;
        for(auto q:queries)
            res.push_back(ispre[q[0]][q[1]]);
        return res;
    }   
    void dfs(int src,vector<int> adj[],vector<vector<bool>> &ispre,vector<bool> &vis,int node)
    {
        vis[node]=true;
        ispre[src][node]=true;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(src,adj,ispre,vis,it);
        }
    }
};