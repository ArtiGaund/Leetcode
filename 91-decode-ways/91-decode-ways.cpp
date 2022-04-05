class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=(s[0]=='0'?0:1);
        for(int i=2;i<=n;i++)
        {
            int onedigit=stoi(s.substr(i-1,1));
            int twodigit=stoi(s.substr(i-2,2));
            if(onedigit>=1) dp[i]+=dp[i-1];
            if(twodigit>=10 and twodigit<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};