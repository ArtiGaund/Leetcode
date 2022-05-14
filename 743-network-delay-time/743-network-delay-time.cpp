class Solution {
public:
    vector<pair<int,int>> adj[101];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto time:times)
        {
            int source=time[0];
            int dest=time[1];
            int travelTime=time[2];
            adj[source].push_back({travelTime,dest});
        }
        vector<int> signalRecievedAt(n+1,INT_MAX);
        dijkstra(signalRecievedAt,k,n);
        int ans=INT_MIN;
        for(int i=1;i<=n;i++) ans=max(ans,signalRecievedAt[i]);
        return ans==INT_MAX?-1:ans;
    }
    void dijkstra(vector<int> &signalRecievedAt,int source,int n)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        signalRecievedAt[source]=0;
        while(!pq.empty())
        {
            int curNodeTime=pq.top().first;
            int curNode=pq.top().second;
            pq.pop();
            if(curNodeTime>signalRecievedAt[curNode]) continue;
            for(auto edge:adj[curNode])
            {
                int time=edge.first;
                int neighbor=edge.second;
                if(signalRecievedAt[neighbor]>curNodeTime+time)
                {
                    signalRecievedAt[neighbor]=curNodeTime+time;
                    pq.push({signalRecievedAt[neighbor],neighbor});
                }
            }
        }
    }
};