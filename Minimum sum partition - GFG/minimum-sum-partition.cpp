// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    
	    return topdown(arr,dp,0,0,0,n);
	} 
	int topdown(int arr[],vector<vector<int>> &dp,int i,int sum1,int sum2,int n)
	{
	    if(i==n) return abs(sum1-sum2);
	    if(dp[i][sum1]==-1)
	    {
	        int diff1=topdown(arr,dp,i+1,sum1+arr[i],sum2,n);
	        int diff2=topdown(arr,dp,i+1,sum1,sum2+arr[i],n);
	        dp[i][sum1]=min(diff1,diff2);
	    }
	    return dp[i][sum1];
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends