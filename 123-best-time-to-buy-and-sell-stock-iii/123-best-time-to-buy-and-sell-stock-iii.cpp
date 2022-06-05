class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit=0;
                    if(buy)
                    {
                        int take=-prices[i]+prev[0][cap];
                        int nottake=0+prev[1][cap];
                        profit=max(take,nottake);
                    }
                    else
                    {
                        int take=prices[i]+prev[1][cap-1];
                        int nottake=0+prev[0][cap];
                        profit=max(take,nottake);
                    }
                    cur[buy][cap]=profit;
                }
            }
            prev=cur;
        }
        return prev[1][2];
    }
};