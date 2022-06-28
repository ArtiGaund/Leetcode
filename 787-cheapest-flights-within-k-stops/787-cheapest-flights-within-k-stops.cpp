#define tu tuple<int,int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n+1];
        for(auto f:flights) graph[f[0]].push_back({f[1],f[2]});
        priority_queue<tu,vector<tu>,greater<tu>> pq;
        vector<vector<bool>> vis(n,vector<bool>(k+2,0));
        pq.push({0,src,k+1});
        vis[0][k]=1;
        while(!pq.empty())
        {
            auto [cost,u,stops]=pq.top();
            pq.pop();
            if(u==dst) return cost;
            if(!stops) continue;
            if(vis[u][stops]) continue;
            vis[u][stops]=1;
            for(auto it:graph[u])
                pq.push({cost+it.second,it.first,stops-1});
        }
        return -1;
    }
};