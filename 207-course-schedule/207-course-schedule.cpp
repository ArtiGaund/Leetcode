class Solution {
public:
    //dfs
    bool isCycle(int node,vector<int> adj[],vector<int> &vis)
    {
        if(vis[node]==1) return true;
        if(vis[node]==0)
        {
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(isCycle(it,adj,vis))
                    return true;
            }
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(isCycle(i,adj,vis)) return false;
        }
        return true;
    }
};