class Solution {
public:
    void bfs(vector<int> &signal,vector<pair<int,int>> adj[],int k,int time)
    {
        queue<int> q;
        q.push(k);
        signal[k]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto e:adj[node])
            {
                int t=e.first,neighbor=e.second;
                int arrivalTime=t+signal[node];
                if(signal[neighbor]>arrivalTime)
                {
                    signal[neighbor]=arrivalTime;
                    q.push(neighbor);
                }
            }
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
        bfs(signal,adj,k,0);
        int ans=INT_MIN;
        for(int node=1;node<=n;node++) ans=max(ans,signal[node]);
        return ans==INT_MAX?-1:ans;
    }
};