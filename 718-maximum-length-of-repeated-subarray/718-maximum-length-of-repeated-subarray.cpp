class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size(),m=B.size();
        vector<vector<int>> dp(2,vector<int>(m+1,0));
        int maxlen=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i%2][j]=1+dp[(i-1)%2][j-1];
                    if(maxlen<dp[i%2][j])
                        maxlen=dp[i%2][j];
                }
                else
                    dp[i%2][j]=0;
            }
        }
        return maxlen;
    }
};