class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs=LCS(str1,str2);
        string res="";
        int i=0,j=0;
        for(char c:lcs)
        {
            while(str1[i]!=c) res+=str1[i++];
            while(str2[j]!=c) res+=str2[j++];
            res+=c;
            i++;
            j++;
        }
        return res+str1.substr(i)+str2.substr(j);
    }
    string LCS(string s1,string s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<string>> dp(n+1,vector<string>(m+1,""));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s1[i]==s2[j])
                    dp[i+1][j+1]=dp[i][j]+s1[i];
                else
                    dp[i+1][j+1]=(dp[i+1][j].size()>dp[i][j+1].size()?dp[i+1][j]:dp[i][j+1]);
            }
        }
        return dp[n][m];
    }
};