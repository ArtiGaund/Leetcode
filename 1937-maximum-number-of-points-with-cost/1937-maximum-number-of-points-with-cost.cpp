class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows=points.size();
        int cols=points[0].size();
        vector<long long> dp(cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                dp[j]+=points[i][j];
            //left to right
            for(int j=1;j<cols;j++)
                dp[j]=max(dp[j],dp[j-1]-1);
            //right to left
            for(int j=cols-2;j>=0;j--)
                dp[j]=max(dp[j],dp[j+1]-1);
        }
        long long maxPoints=0;
        for(int i=0;i<cols;i++) maxPoints=max(maxPoints,dp[i]);
        return maxPoints;
    }
};