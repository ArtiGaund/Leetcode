class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<int> dp(n,0),prev(n,0);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                    dp[j]=prev[j-1]+2;
                else
                    dp[j]=max(prev[j],dp[j-1]);
            }
            dp.swap(prev);
        }
        return prev[n-1];
    }
};