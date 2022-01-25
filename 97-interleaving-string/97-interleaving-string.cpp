class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size(),p=s3.size();
        if(m+n!=p) return false;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(s1,0,s2,0,s3,0,dp);
    }
    bool solve(string s1,int i,string s2,int j,string s3,int k,vector<vector<int>> &dp)
    {
        if(i==s1.size()) return s2.substr(j)==s3.substr(k);
        if(j==s2.size()) return s1.substr(i)==s3.substr(k);
        if(dp[i][j]>=0) return dp[i][j]==1?true:false;
        bool ans=false;
        if((s3[k]==s1[i] and solve(s1,i+1,s2,j,s3,k+1,dp)) or (s3[k]==s2[j] and solve(s1,i,s2,j+1,s3,k+1,dp))) ans=true;
        dp[i][j]=ans?1:0;
        return ans;
    }
};