class Solution {
public:
    void dijkstra(vector<int> &signal,vector<pair<int,int>> adj[],int k,int n)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        signal[k]=0;
        while(!pq.empty())
        {
            auto [time,node]=pq.top();
            pq.pop();
            if(time>signal[node]) continue;
            for(auto e:adj[node])
            {
                int t=e.first,neighbor=e.second;
                if(signal[neighbor]>time+t)
                {
                    signal[neighbor]=time+t;
                    pq.push({signal[neighbor],neighbor});
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
        // for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
        vector<int> signal(n+1,INT_MAX);
        dijkstra(signal,adj,k,n);
        int ans=INT_MIN;
        for(int node=1;node<=n;node++) ans=max(ans,signal[node]);
        return ans==INT_MAX?-1:ans;
    }
};