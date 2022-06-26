class Solution {
public:
    void dfs(vector<int> graph[],int node,vector<int> &vis)
    {
        if(vis[node]) return;
        vis[node]=1;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                dfs(graph,it,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;
        vector<int> graph[n+1];
        for(auto c:connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(graph,i,vis);
            }
        }
        return count-1;
    }
};