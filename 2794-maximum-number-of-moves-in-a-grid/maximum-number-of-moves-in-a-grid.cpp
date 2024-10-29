class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(2,0));
        for(int i=0;i<m;i++) dp[i][0]=1;
        int maxMoves=0;
        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j]>grid[i][j-1] and dp[i][0]>0){
                    dp[i][1]=max(dp[i][1],dp[i][0]+1);
                }
                if(i-1>=0 and grid[i][j]>grid[i-1][j-1] and dp[i-1][0]>0){
                    dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
                }
                if(i+1<m and grid[i][j]>grid[i+1][j-1] and dp[i+1][0]>0){
                    dp[i][1]=max(dp[i][1],dp[i+1][0]+1);
                }
                maxMoves=max(maxMoves,dp[i][1]-1);
            }
            for(int k=0;k<m;k++){
                dp[k][0]=dp[k][1];
                dp[k][1]=0;
            }
        }
        return maxMoves;
    }
};