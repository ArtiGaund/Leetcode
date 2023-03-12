//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<2*n-1;j++)
            {
                int top=i;
                int bottom=j;
                int right=2*n-2-j;
                int left=2*n-2-i;
                int a=min(top,bottom);
                int b=min(left,right);
                cout<<(n-min(a,b))<<" ";
                
            }
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends