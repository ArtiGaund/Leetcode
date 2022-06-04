class Solution {
public:
    int solve(string s1,string s2,vector<vector<int>> &dp,int i,int j)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=solve(s1,s2,dp,i-1,j-1);
        int in=1+solve(s1,s2,dp,i,j-1);
        int d=1+solve(s1,s2,dp,i-1,j);
        int r=1+solve(s1,s2,dp,i-1,j-1);
        return dp[i][j]=min({in,d,r});
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s1,s2,dp,n-1,m-1);
    }
};