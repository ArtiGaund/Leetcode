class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int maxlen=0,start,end;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<=n-1;j++)
            {
                if(i==j) dp[i][j]=1;
                else if(s[i]==s[j])
                {
                    if(j-i==1) //len 2
                        dp[i][j]=1;
                    else dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j] and maxlen<=j-i)
                {
                    maxlen=j-i;
                    start=i;
                    end=j;
                }
            }
        }
        string res=s.substr(start,end-start+1);
        return res;
    }
};