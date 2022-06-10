// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &a,int n,vector<string> &res,string move,int di[],int dj[],vector<vector<bool>> &vis)
    {
        if(i==n-1 and j==n-1)
        {
            res.push_back(move);
            return;
        }
        string dir="DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int nexti=i+di[ind];
            int nextj=j+dj[ind];
            if(nexti>=0 and nextj>=0 and nexti<n and nextj<n and !vis[nexti][nextj] and a[nexti][nextj]==1)
            {
                vis[i][j]=1;
                solve(nexti,nextj,a,n,res,move+dir[ind],di,dj,vis);
                vis[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int di[]={1,0,0,-1};
        int dj[]={0,-1,1,0};
        vector<string> res;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        if(m[0][0]==1) solve(0,0,m,n,res,"",di,dj,vis);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends