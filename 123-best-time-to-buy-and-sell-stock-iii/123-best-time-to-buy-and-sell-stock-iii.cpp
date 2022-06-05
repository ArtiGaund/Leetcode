class Solution {
public:
    int solve(vector<int> &p,vector<vector<vector<int>>> &dp,int n,int index,int buy,int cap)
    {
        if(cap==0) return 0;
        if(index==n) return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        int profit=0;
        if(buy)
        {
            int take=-p[index]+solve(p,dp,n,index+1,0,cap);
            int nottake=0+solve(p,dp,n,index+1,1,cap);
            profit=max(take,nottake);
        }
        else
        {
            int take=p[index]+solve(p,dp,n,index+1,1,cap-1);
            int nottake=0+solve(p,dp,n,index+1,0,cap);
            profit=max(take,nottake);
        }
        return dp[index][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,dp,n,0,1,2);
    }
};