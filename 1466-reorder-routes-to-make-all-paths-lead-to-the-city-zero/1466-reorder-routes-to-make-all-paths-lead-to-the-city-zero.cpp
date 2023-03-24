class Solution {
public:
    int count=0;
    void dfs(int node,int parent,vector<pair<int,int>> adj[])
    {
        for(auto &[child,sign]:adj[node])
        {
            if(child!=parent)
            {
                count+=sign;
                dfs(child,node,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        for(auto c:connections)
        {
            adj[c[0]].push_back({c[1],1});
            adj[c[1]].push_back({c[0],0});
        }
        dfs(0,-1,adj);
        return count;
    }
};