class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis,vector<int> &check)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis,check))
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it])
            {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<graph[i].size();j++)
                adj[i].push_back(graph[i][j]);
        vector<int> vis(n,0),pathVis(n,0),check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,pathVis,check);
        }
        vector<int> safenodes;
        for(int i=0;i<n;i++)
            if(check[i]==1) safenodes.push_back(i);
        return safenodes;
    }
};