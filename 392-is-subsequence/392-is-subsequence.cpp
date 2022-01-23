class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size(),m=s.size();
        if(m==0) return 1;
        if(n==0 or m>n) return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j];
            }
        }
        if(dp[n][m]>0) return true;
        return false;
    }
};