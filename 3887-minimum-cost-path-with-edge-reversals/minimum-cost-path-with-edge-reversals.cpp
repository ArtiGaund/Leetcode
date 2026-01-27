class Solution {
    using PII = pair<int,int>;
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> graph(n);
        for(auto &e:edges){
            int x=e[0],y=e[1],w=e[2];
            graph[x].push_back({y,w});
            graph[y].push_back({x,w*2});
        }
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n,false);
        dist[0]=0;
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int x=pq.top().second;
            pq.pop();
            if(x==n-1) return dist[x];
            if(vis[x]) continue;
            vis[x]=true;
            for(auto &[y,w]:graph[x]){
                if(dist[x]+w<dist[y]){
                    dist[y]=dist[x]+w;
                    pq.push({dist[y],y});
                }
            }
        }
        return -1;
    }
};