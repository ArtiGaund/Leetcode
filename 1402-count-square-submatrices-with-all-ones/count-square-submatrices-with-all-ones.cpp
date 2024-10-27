class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int total{matrix[0][0]};
        dp[0][0]=matrix[0][0];
        for(int i=1;i<n;i++) dp[i][0]=matrix[i][0],total+=matrix[i][0];
        for(int j=1;j<m;j++) dp[0][j]=matrix[0][j],total+=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j])
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                else dp[i][j]=0;
                total+=dp[i][j];
            }
        }
        return total;
    }
};