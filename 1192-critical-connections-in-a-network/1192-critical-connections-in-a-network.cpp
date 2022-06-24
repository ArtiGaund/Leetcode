class Solution {
public:
    vector<vector<int>> bridge;
    vector<int> time,low;
    vector<bool> vis;
    void dfs(int node,int parent,int &timer,vector<int> graph[])
    {
        vis[node]=1;
        low[node]=time[node]=timer++;
        for(auto it:graph[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,node,timer,graph);
                low[node]=min(low[node],low[it]);
                if(low[it]>time[node]) bridge.push_back({node,it});
            }
            else low[node]=min(low[node],time[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n+1];
        for(auto &c:connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        time.resize(n,-1);
        low.resize(n,-1);
        vis.resize(n,false);
        int timer=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,-1,timer,graph);
        }
        return bridge;
    }
};