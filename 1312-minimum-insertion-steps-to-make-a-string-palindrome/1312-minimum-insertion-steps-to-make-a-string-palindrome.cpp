class Solution {
public:
    int minInsertions(string s) {
        if(s.size()==0) return 0;
        return s.size()-LPS(s);
    }
    int LPS(string s)
    {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++) //all subsequence of len 1 is palindrome
            dp[i][i]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                    dp[i][j]=2+dp[i+1][j-1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};