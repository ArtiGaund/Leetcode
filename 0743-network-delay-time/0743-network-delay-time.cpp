class Solution {
public:
    void solve(vector<pair<int,int>> graph[],vector<int> &signal,int k)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        signal[k]=0;
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto e:graph[node])
            {
                int t=e.first;
                int neighbor=e.second;
                int arrivalTime=time+t;
                if(signal[neighbor]>arrivalTime)
                {
                    signal[neighbor]=arrivalTime;
                    pq.push({arrivalTime,neighbor});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n+1];
        for(auto t:times)
            graph[t[0]].push_back({t[2],t[1]});
        vector<int> signal(n+1,INT_MAX);
        solve(graph,signal,k);
        int res=INT_MIN;
        for(int i=1;i<=n;i++)
            res=max(res,signal[i]);
        return (res==INT_MAX?-1:res);
    }
};