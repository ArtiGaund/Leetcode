//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto r:roads)
        {
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
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

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends