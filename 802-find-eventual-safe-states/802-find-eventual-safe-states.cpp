class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &graph)
    {
        if(vis[node]==1) return false;
        if(vis[node]==2) return true;
        vis[node]=1;
        for(auto it:graph[node])
            if(!dfs(it,vis,graph)) return false;
        vis[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> res,vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(dfs(i,vis,graph)) res.push_back(i);
        }
        return res;
    }
};