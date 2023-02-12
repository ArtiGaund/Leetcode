//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int start=0,end=n-1;
	    while(start<end)
	    {
	        int mid=start+(end-start)/2;
	        if(mid<end and arr[mid]>arr[mid+1]) return mid+1;
	        if(mid>start and arr[mid-1]>arr[mid]) return mid;
	        if(arr[start]<arr[mid]) start=mid+1;
	        else end=mid-1;
	    }
	    return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends