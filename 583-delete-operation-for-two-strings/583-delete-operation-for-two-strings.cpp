class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs=LCS(word1,word2);
        int res=(word1.size()-lcs)+(word2.size()-lcs);
        return res;
    }
    int LCS(string s1,string s2)
    {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};