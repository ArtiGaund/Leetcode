class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++) dp[i][i]=true; //all substring of len 1 is palindrome
        int maxlen=1;
        int start=0;
        for(int i=0;i<n-1;i++) //check substring of len 2
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
            }
        }
        for(int k=3;k<=n;k++) //check substring of len> 3. k is len of substring
        {
            for(int i=0;i<n-k+1;i++) //fix start
            {
                int j=i+k-1; //end of substring from i and k
                if(dp[i+1][j-1] and s[i]==s[j])
                {
                    dp[i][j]=true;
                    if(k>maxlen)
                    {
                        start=i;
                        maxlen=k;
                    }
                }
            }
        }
        string res="";
        for(int i=start;i<start+maxlen;i++) res+=s[i];
        return res;
    }
};