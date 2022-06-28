class Solution {
public:
    void dfs(vector<int> &signal,vector<pair<int,int>> adj[],int node,int time)
    {
        if(time>=signal[node]) return;
        signal[node]=time;
        for(auto e:adj[node])
        {
            int t=e.first;
            int neighbor=e.second;
            dfs(signal,adj,neighbor,time+t);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto t:times)
        {
            adj[t[0]].push_back({t[2],t[1]});
        }
        for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
        vector<int> signal(n+1,INT_MAX);
        dfs(signal,adj,k,0);
        int ans=INT_MIN;
        for(int node=1;node<=n;node++) ans=max(ans,signal[node]);
        return ans==INT_MAX?-1:ans;
    }
};