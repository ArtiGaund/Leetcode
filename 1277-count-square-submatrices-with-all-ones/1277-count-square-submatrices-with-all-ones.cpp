class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
         int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
         int total{arr[0][0]};
        dp[0][0]=arr[0][0];
        for(int i=1;i<n;i++) dp[i][0] = arr[i][0], total += arr[i][0];
        for(int j=1;j<m;j++) dp[0][j] = arr[0][j], total += arr[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(arr[i][j])
            dp[i][j] = 1+min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            else dp[i][j]=0;
            total += dp[i][j];
            }
        }
        return total;
    }
};