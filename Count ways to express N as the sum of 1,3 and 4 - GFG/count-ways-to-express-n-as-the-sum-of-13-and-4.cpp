// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long countWays(int n) {
        // code here
        vector<long long> dp(n+1,0);
        return solve(dp,n);
    }
    long long solve(vector<long long> &dp,int n)
    {
        if(n<=2) return 1;
        if(n==3) return 2;
        if(dp[n]==0)
        {
            long long step1=solve(dp,n-1);
            long long step3=solve(dp,n-3);
            long long step4=solve(dp,n-4);
            dp[n]=(step1+step3+step4)%(1000000007);
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends