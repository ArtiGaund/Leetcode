class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int Threshold) {
        vector<pair<int,int>> adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int cityno,cntCity=1e9;
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,1e9);
            dist[i]=0;
            pq.push({0,i});
            while(!pq.empty())
            {
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node])
                {
                    int adjNode=it.first;
                    int edgeW=it.second;
                    if(dis+edgeW<dist[adjNode])
                    {
                        dist[adjNode]=dis+edgeW;
                        pq.push({dis+edgeW,adjNode});
                    }
                }
            }
            int cnt=0;
            for(int j=0;j<n;j++)
                if(dist[j]<=Threshold and dist[j]!=1e9)
                    cnt++;
            if(cnt<=cntCity)
            {
                cntCity=cnt;
                cityno=i;
            }
        }
        return cityno;
    }
};