class Solution {
public:
    pair<int,int> countZeroOne(string s)
    {
        int zero=0,one=0;
        for(char c:s)
        {
            if(c=='0') zero++;
            else one++;
        }
        return {zero,one};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string s:strs)
        {
           pair<int,int> temp=countZeroOne(s);
            int zero=temp.first;
            int one=temp.second;
            for(int i=m;i>=zero;i--)
            {
                for(int j=n;j>=one;j--)
                    dp[i][j]=max(dp[i][j],1+dp[i-zero][j-one]);
            }
        }
        return dp[m][n];
    }
};