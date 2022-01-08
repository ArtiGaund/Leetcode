class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,0,n-1,grid,dp);
    }
    int solve(int row,int col1,int col2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
    {
        if(col1<0 or col1>=grid[0].size() or col2<0 or col2>=grid[0].size()) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int res=0;
        res+=grid[row][col1];
        if(col1!=col2) res+=grid[row][col2];
        if(row!=grid.size()-1)
        {
            int max_val=0;
            for(int c1=col1-1;c1<=col1+1;c1++)
            {
                for(int c2=col2-1;c2<=col2+1;c2++)
                    max_val=max(max_val,solve(row+1,c1,c2,grid,dp));
            }
            res+=max_val;
        }
        dp[row][col1][col2]=res;
        return res;
    }
};