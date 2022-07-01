class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> graph[])
    {
        if(vis[node]) return;
        vis[node]=1;
        for(auto it:graph[node])
        {
            if(!vis[it]) dfs(it,vis,graph);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        if(size<n-1) return -1;
        vector<int> graph[n+1];
        for(auto c:connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        int component=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                component++;
                dfs(i,vis,graph);
            }
        }
        return component-1;
    }
};