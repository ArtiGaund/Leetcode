class Solution {
public:
    int dfs(vector<vector<int>>& arr,int i,int j,vector<vector<int>> &dp) {
        if(dp[i+1][j]!=INT_MAX)
            return dp[i+1][j];
        int s=INT_MAX;
        if(j==arr.size())
            return 0;
        for(int p=0;p<arr[j].size();p++){
            if(p==i)
                continue;
            else
                s=min(s,arr[j][p]+dfs(arr,p,j+1,dp));
        }
        return dp[i+1][j]=s;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>>dp(202, vector<int>(202,INT_MAX));
        return dfs(arr,-1,0,dp);
    }
};