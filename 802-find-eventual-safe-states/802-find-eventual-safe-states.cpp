class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int node,vector<int> &vis)
    {
        if(vis[node]==1) return false;
        if(vis[node]==2) return true;
        vis[node]=1;
        for(auto it:graph[node])
        {
            if(dfs(graph,it,vis)==false) return false;
        }
        vis[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> res,vis(n,0);
        for(int i=0;i<n;i++)
            if(dfs(graph,i,vis)) res.push_back(i);
        return res;
    }
};