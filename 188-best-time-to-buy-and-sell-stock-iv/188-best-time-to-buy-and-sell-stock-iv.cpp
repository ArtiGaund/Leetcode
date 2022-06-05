class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(buy==1)
                    {
                        int take=-prices[index]+prev[0][cap];
                        int nottake=0+prev[1][cap];
                        cur[buy][cap]=max(take,nottake);
                    }
                    else
                    {
                        int take=prices[index]+prev[1][cap-1];
                        int nottake=0+prev[0][cap];
                        cur[buy][cap]=max(take,nottake);
                    }
                }
                prev=cur;
            }
        }
        return prev[1][k];
    }
};