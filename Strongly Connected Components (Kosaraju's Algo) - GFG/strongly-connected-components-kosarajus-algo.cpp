//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	            dfs(it,vis,adj,st);
	    }
	    st.push(node);
	}
	void dfs3(int node,vector<int> adjT[],vector<int> &vis)
	{
	    vis[node]=1;
	    for(auto it:adjT[node])
	    {
	        if(!vis[it])
	            dfs3(it,adjT,vis);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        //step 1: sort according to finish time
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,vis,adj,st);
        }
        // step 2: reverse graph edges
        vector<int> adjT[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            {
                //i->it => it->i
                adjT[it].push_back(i);
            }
        }
        // step 3: do dfs to count
        int scc=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
                {
                    scc++;
                    dfs3(node,adjT,vis);
                }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends