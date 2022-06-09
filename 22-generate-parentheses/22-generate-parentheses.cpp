class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0]={""};
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                vector<string> left=dp[j];
                vector<string> right=dp[i-j-1];
                for(auto &l:left)
                    for(auto &r:right)
                        dp[i].push_back('('+l+')'+r);
            }
        }
        return dp[n];
    }
};