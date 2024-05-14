class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++) dp.push_back(grid[i]);
        int res=INT_MIN;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                res=max(res,backtrack(i,j));
        return res;
    }
    int backtrack(int i,int j){
        if(i<0 or i>=m or j<0 or j>=n or dp[i][j]==0) return 0;
        int temp=dp[i][j];
        dp[i][j]=0;
        int r1=backtrack(i-1,j);
        int r2=backtrack(i+1,j);
        int c1=backtrack(i,j-1);
        int c2=backtrack(i,j+1);
        dp[i][j]=temp;
        return dp[i][j]+max({r1,r2,c1,c2});
    }
};