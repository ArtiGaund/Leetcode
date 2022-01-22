class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++) //all substring of len 1 is palindrome
            dp[i][i]=true;
        int maxlen=1;
        int start=0;
        for(int i=0;i<n-1;i++) // check for len of 2
        {
            if(s[i]==s[i+1])
            {
                start=i;
                dp[i][i+1]=true;
                maxlen=2;
            }
        }
        for(int k=3;k<=n;k++) //check of len> 2. k is len
        {
            for(int i=0;i<n-k+1;i++) //fixing starting index
            {
                int j=i+k-1; // end index by i and k
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