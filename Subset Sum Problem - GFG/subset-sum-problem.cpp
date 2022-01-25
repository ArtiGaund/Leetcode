// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<vector<bool>> dp(N,vector<bool>(sum+1));
        for(int i=0;i<N;i++) dp[i][0]=true;
        for(int j=1;j<=sum;j++)
            dp[0][j]=(arr[0]==j?true:false);
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(dp[i-1][j]) dp[i][j]=dp[i-1][j];
                else if(j>=arr[i])
                    dp[i][j]=dp[i-1][j-arr[i]];
            }
        }
        return dp[N-1][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends