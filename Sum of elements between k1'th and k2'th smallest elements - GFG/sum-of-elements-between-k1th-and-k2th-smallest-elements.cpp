//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    struct numComp
    {
        bool operator()(const long long &x,const long long &y)
        {
            return x>y;
        }
    };
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long,vector<long long>,numComp> minHeap;
        for(long long i=0;i<N;i++)
            minHeap.push(A[i]);
        for(long long i=0;i<K1;i++) minHeap.pop();
        long long eleSum=0;
        for(int i=0;i<K2-K1-1;i++)
        {
            eleSum+=minHeap.top();
            minHeap.pop();
        }
        return eleSum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends