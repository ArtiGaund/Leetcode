//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
    public:
    vector<int> rank,parent;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findParent(int u)
    {
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionset(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        vector<int> res;
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1)
            {
                res.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
            for(auto d:dir)
            {
                int adjr=row+d.first;
                int adjc=col+d.second;
                if(adjr>=0 and adjr<n and adjc>=0 and adjc<m)
                {
                    if(vis[adjr][adjc]==1)
                    {
                        int nodeNo=row*m+col;
                        int adjNo=adjr*m+adjc;
                        if(ds.findParent(nodeNo)!=ds.findParent(adjNo))
                        {
                            count--;
                            ds.unionset(nodeNo,adjNo);
                        }
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends