class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto f:flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }
        //{stops,{node,dist}}
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgeW=it.second;
                if(cost+edgeW<dist[adjNode] and stops<=k)
                {
                    dist[adjNode]=cost+edgeW;
                    q.push({stops+1,{adjNode,cost+edgeW}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};