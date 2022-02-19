// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int,int> pii;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pii,vector<pii>,greater<pii>> minH;
        vector<int> distTo(V+1,INT_MAX);
        distTo[S]=0;
        minH.push({0,S});
        while(!minH.empty())
        {
            int dis=minH.top().first;
            int prev=minH.top().second;
            minH.pop();
            for(auto it:adj[prev])
            {
                int next=it[0];
                int nextDis=it[1];
                if(distTo[next]>distTo[prev]+nextDis)
                {
                    distTo[next]=distTo[prev]+nextDis;
                    minH.push({distTo[next],next});
                }
            }
        }
        return distTo;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends