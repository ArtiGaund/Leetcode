class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> adj[n];
        for(auto e:richer) 
            adj[e[1]].push_back(e[0]);
        vector<int> res(n,-1);
        for(int node=0;node<n;node++)
            dfs(node,adj,res,quiet);
        return res;
    }
    int dfs(int node,vector<int> adj[],vector<int> &res,vector<int> quiet)
    {
        if(res[node]==-1)
        {
            res[node]=node;
            for(auto it:adj[node])
            {
                int cad=dfs(it,adj,res,quiet);
                if(quiet[cad]<quiet[res[node]])
                    res[node]=cad;
            }
        }
        return res[node];
    }
};