//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n-1;j++) cout<<" ";
            for(char ch='A';ch<='A'+i;ch++) cout<<ch;
            int j=i-1;
            if(j>=0) for(char ch='A'+j;ch>='A';ch--) cout<<ch;
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends