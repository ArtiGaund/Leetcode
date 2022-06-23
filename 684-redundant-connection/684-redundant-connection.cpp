class Solution {
public:
    bool dfs(int node,vector<int> graph[],int n,vector<int> &vis,int parent,int x,int y)
    {
        vis[node]=1;
        for(auto it:graph[node])
        {
            if(vis[it]==-1 and dfs(it,graph,n,vis,node,x,y)) return true;
            else if(vis[it]==1 and it!=parent and it==x and node==y) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> graph[n+1];
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i=n-1;i>=0;i--)
        {
            vector<int> vis(n+1,-1);
            if(dfs(edges[i][0],graph,n,vis,-1,edges[i][0],edges[i][1])) 
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};