class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n=102;
        vector<vector<double>> dp(n,vector<double>(n));
        dp[0][0]=(double)poured;
        for(int i=0;i<=query_row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double q=(dp[i][j]-1.0)/2.0;
                if(q>0)
                {
                    dp[i+1][j]+=q;
                    dp[i+1][j+1]+=q;
                }
            }
        }
        if(dp[query_row][query_glass]<1)
            return dp[query_row][query_glass];
        return 1;
    }
};