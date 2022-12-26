//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        if(src.first==destination.first and src.second==destination.second) return 0;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[src.first][src.second]=0;
        q.push({0,{src.first,src.second}});
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(auto d:dir)
            {
                int r=row+d.first;
                int c=col+d.second;
                if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1 and dis+1<dist[r][c])
                {
                    dist[r][c]=dis+1;
                    if(r==destination.first and c==destination.second) return dis+1;
                    q.push({dist[r][c],{r,c}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends