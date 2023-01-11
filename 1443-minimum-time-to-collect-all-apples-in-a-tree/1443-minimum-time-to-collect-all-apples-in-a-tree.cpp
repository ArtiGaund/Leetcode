class Solution {
public:
    int dfs(int node,int parent,vector<int> adj[],vector<bool> &hasApple)
    {
        int totalTime=0,childTime=0;
        for(auto child:adj[node])
        {
            if(child==parent) continue;
            childTime=dfs(child,node,adj,hasApple);
            if(childTime or hasApple[child]) totalTime+=childTime+2;
        }
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       vector<int> adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};