class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int left=matrix[i][j];
                if(j-1>=0) left+=dp[i-1][j-1];
                else left+=1e9;
                int right=matrix[i][j];
                if(j+1<m) right+=dp[i-1][j+1];
                else right+=1e9;
                dp[i][j]=min({up,left,right});
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<m;j++)
            mini=min(mini,dp[n-1][j]);
        return mini;
        
    }
};