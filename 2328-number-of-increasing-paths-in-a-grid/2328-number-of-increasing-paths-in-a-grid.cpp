class Solution {
public:
   
    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int mod=1000000007;
    int dfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=0) return dp[i][j];
        int res=1;
        for(auto d:dir)
        {
            int prevI=i+d.first,prevJ=j+d.second;
            if(0<=prevI and prevI<grid.size() and 0<=prevJ and prevJ<grid[0].size() and grid[prevI][prevJ]<grid[i][j])
            {
                res+=dfs(grid,prevI,prevJ,dp);
                res%=mod;
            }
        }
        dp[i][j]=res;
        return res;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                res=(res+dfs(grid,i,j,dp))%mod;
        }
        return res;
    }
};