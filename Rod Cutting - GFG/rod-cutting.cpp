// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        if(n<=0) return 0;
        vector<int> length(n);
        for(int i=0;i<n;i++) length[i]=i+1;
        vector<vector<int>> dp(n,vector<int>(n+1));
        for(int i=0;i<n;i++)
        {
            for(int len=1;len<=n;len++)
            {
                int p1=0,p2=0;
                if(length[i]<=len)
                    p1=price[i]+dp[i][len-length[i]];
                if(i>0)
                    p2=dp[i-1][len];
                dp[i][len]=max(p1,p2);
            }
        }
        return dp[n-1][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends