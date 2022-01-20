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
        vector<int> res(n+1);
        res[0]=0;
        for(int i=1;i<=n;i++)
        {
            int max_val=INT_MIN;
            for(int j=0;j<i;j++)
                max_val=max(max_val,price[j]+res[i-j-1]);
            res[i]=max_val;
        }
        return res[n];
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