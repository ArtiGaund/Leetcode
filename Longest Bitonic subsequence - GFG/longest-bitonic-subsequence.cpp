// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> lds(n,1),ldsrev(n,1);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i-1;j>=0;j--)
	        {
	            if(nums[j]<nums[i])
	                lds[i]=max(lds[i],lds[j]+1);
	        }
	    }
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(nums[j]<nums[i])
	                ldsrev[i]=max(ldsrev[i],ldsrev[j]+1);
	        }
	    }
	    int maxlen=0;
	    for(int i=0;i<n;i++)
	        maxlen=max(maxlen,lds[i]+ldsrev[i]-1);
	   return maxlen;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends