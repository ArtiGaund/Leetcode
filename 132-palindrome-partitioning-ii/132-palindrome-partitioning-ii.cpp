class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 or dp[i+1][j-1])
                        dp[i][j]=true;
                }
            }
        }
        vector<int> cut(n);
        for(int i=n-1;i>=0;i--)
        {
            int mincut=n;
            for(int j=n-1;j>=i;j--)
            {
                if(dp[i][j])
                {
                    mincut=(j==n-1?0:min(mincut,1+cut[j+1]));
                }
            }
            cut[i]=mincut;
        }
        return cut[0];
    }
};