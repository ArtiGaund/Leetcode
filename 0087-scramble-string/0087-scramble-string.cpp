class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        vector dp(n+1,vector(n,vector<int>(n)));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[1][i][j]=(s1[i]==s2[j]);
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n+1-len;i++)
            {
                for(int j=0;j<n+1-len;j++)
                {
                    for(int newLen=1;newLen<len;newLen++)
                    {
                        const vector<int> &dp1=dp[newLen][i];
                        const vector<int> &dp2=dp[len-newLen][i+newLen];
                        dp[len][i][j] |=dp1[j] and dp2[j+newLen];
                        dp[len][i][j] |=dp1[j+len-newLen] and dp2[j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};