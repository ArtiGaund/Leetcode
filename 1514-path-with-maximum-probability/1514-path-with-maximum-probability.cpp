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
        pq.push({1,start});
        prob[start]=1;
        while(!pq.empty())
        {
            auto [w,node]=pq.top();
            pq.pop();
            if(w<prob[node]) continue;
            for(auto it:adj[node])
            {
               if(prob[it.second]<w*it.first)
               {
                   prob[it.second]=w*it.first;
                   pq.push({prob[it.second],it.second});
               }
            }
        }
        return prob[end];
    }
};