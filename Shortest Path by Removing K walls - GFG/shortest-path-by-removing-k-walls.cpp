//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> grid, int n, int m, int k) {
        // code here
        if(n==1 and m==1) return 0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(k+1,0)));
        vis[0][0][k]=1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        int steps=0;
        while(!q.empty())
        {
            steps++;
            int size=q.size();
            while(size--)
            {
                int x=q.front().first.first;
                int y=q.front().first.second;
                int eliminate=q.front().second;
                q.pop();
                for(auto d:dir)
                {
                    int new_x=x+d.first;
                    int new_y=y+d.second;
                    if(new_x==n-1 and new_y==m-1) return steps;
                    if(new_x<0 or new_x>=n or new_y<0 or new_y>=m) continue;
                    if(grid[new_x][new_y]==1 and eliminate==0) continue;
                    int new_eliminate=eliminate-grid[new_x][new_y];
                    if(vis[new_x][new_y][new_eliminate]) continue;
                    q.push({{new_x,new_y},new_eliminate});
                    vis[new_x][new_y][new_eliminate]=1;
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
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends