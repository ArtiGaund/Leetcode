class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++) dp.push_back(grid[i]);
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=max(res,backtrack(i,j));
            }
        }
        if(res==INT_MIN) return 0;
        return res;
    }
    int backtrack(int r,int c)
    {
        if(r<0 or r>=n or c<0 or c>=m or dp[r][c]==0) return 0;
        int temp=dp[r][c];
        dp[r][c]=0;
        int res1=backtrack(r+1,c);
        int res2=backtrack(r-1,c);
        int res3=backtrack(r,c+1);
        int res4=backtrack(r,c-1);
        dp[r][c]=temp;
        return dp[r][c]+max({res1,res2,res3,res4});
    }
};