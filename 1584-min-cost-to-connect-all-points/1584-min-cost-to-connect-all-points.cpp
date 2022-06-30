class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                int x2=points[j][0];
                int y2=points[j][1];
                int dis=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({dis,j});
                adj[j].push_back({dis,i});
            }
        }
        // Prim's
        int res=0;
        unordered_set<int> vis;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); // (cost,point)
        while(vis.size()<n)
        {
            auto [cost,i]=pq.top();
            pq.pop();
            if(vis.count(i)) continue;
            res+=cost;
            vis.insert(i);
            for(auto [neiCost,nei]:adj[i])
            {
                if(vis.count(nei)==0)
                {
                    pq.push({neiCost,nei});
                }
            }
        }
        return res;
    }
};