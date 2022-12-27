class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<long long int,long long int>> adj[n];
        for(auto r:roads)
        {
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
        vector<long long int> dist(n,LONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        long long int mod=(1e9+7);
        while(!pq.empty())
        {
            long long int dis=pq.top().first;
            long long int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgeW=it.second;
                //this is the first time I am coming with this shortest distance
                if(dis+edgeW<dist[adjNode])
                {
                    dist[adjNode]=dis+edgeW;
                    pq.push({dis+edgeW,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dis+edgeW==dist[adjNode])
                ways[adjNode]=(ways[node]+ways[adjNode])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};