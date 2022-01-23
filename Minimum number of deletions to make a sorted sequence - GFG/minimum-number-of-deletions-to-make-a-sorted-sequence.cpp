// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minDeletions(int nums[], int n) 
	{ 
	    // Your code goes here
	    vector<int> dp(n,1);
	    int maxlen=1;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j] and dp[i]<=dp[j])
	            {
	                dp[i]=dp[j]+1;
	                maxlen=max(maxlen,dp[i]);
	            }
	        }
	    }
	    return n-maxlen;
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends