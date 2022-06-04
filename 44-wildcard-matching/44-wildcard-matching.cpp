class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0]=true;
        for(int j=1;j<=m;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++)
        {
            bool f1=true;
            for(int c=1;c<=i;c++)
            {
                if(p[c-1]!='*')
                {
                    f1=false;
                    break;
                }
            }
            dp[i][0]=f1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[i-1]==s[j-1] or p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')
                    dp[i][j]=dp[i-1][j] or dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};