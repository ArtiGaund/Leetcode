class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathVis,vector<int> &check)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,graph,vis,pathVis,check)==true)
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
        vector<int> vis(n,0),pathVis(n,0),check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,graph,vis,pathVis,check);
        }
        vector<int> res;
        for(int i=0;i<n;i++)
            if(check[i]==1) res.push_back(i);
        return res;
    }
};