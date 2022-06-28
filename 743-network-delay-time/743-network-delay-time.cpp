class Solution {
public:
    void dfs(vector<int> &signal,vector<pair<int,int>> adj[],int node,int time,int n)
    {
        if(time>=signal[node]) return;
        signal[node]=time;
        for(auto e:adj[node])
        {
            int t=e.first;
            int neighbor=e.second;
            dfs(signal,adj,neighbor,time+t,n);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto time:times)
        {
            adj[time[0]].push_back({time[2],time[1]});
        }
        for(int i=1;i<=n;i++)
            sort(adj[i].begin(),adj[i].end());
        vector<int> signal(n+1,INT_MAX);
        dfs(signal,adj,k,0,n);
        int ans=INT_MIN;
        for(int node=1;node<=n;node++)
            ans=max(ans,signal[node]);
        return ans==INT_MAX?-1:ans;
    }
};