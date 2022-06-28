class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double,int>> adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            double w=succProb[i];
            
            adj[a].push_back({w,b});
            adj[b].push_back({w,a});
        }
        
        vector<double> prob(n,0);
        priority_queue<pair<double,int>> pq;
        prob[start]=1; // max prob is 1 and that will be of source
        
        pq.push({1,start});
        while(!pq.empty())
        {
            int node =pq.top().second;
            double w=pq.top().first;
            pq.pop();
            
            if(w < prob[node])
                continue;
            
            for(auto x:adj[node])
            {
                if(prob[x.second] < w*x.first)
                {
                    prob[x.second]=w*x.first;
                    pq.push({prob[x.second],x.second});
                }
            }
        }
        return prob[end];
    }
};