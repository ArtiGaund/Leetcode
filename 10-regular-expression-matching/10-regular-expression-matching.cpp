class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+2,vector<bool>(m+2,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 and j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else if(j==0)
                {
                    char pc=p[i-1];
                    if(pc=='*') dp[i][j]=dp[i-2][j];
                    else dp[i][j]=0;
                }
                else
                {
                    char pc=p[i-1];
                    char sc=s[j-1];
                    if(pc=='*')
                    {
                        dp[i][j]=dp[i-2][j];
                        char sec_p=p[i-2];
                        if(sec_p=='.' or sec_p==sc) dp[i][j]=dp[i][j] or dp[i][j-1];
                    }
                    else if(pc=='.' or pc==sc) dp[i][j]=dp[i-1][j-1];
                    else dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
    }
};