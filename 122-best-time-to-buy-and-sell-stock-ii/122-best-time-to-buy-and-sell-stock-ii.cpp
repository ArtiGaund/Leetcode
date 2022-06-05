class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0),cur(2,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    int take=-prices[index]+ahead[0];
                    int nottake=0+ahead[1];
                    profit=max(take,nottake);
                }
                else
                {
                    int take=prices[index]+ahead[1];
                    int nottake=0+ahead[0];
                    profit=max(take,nottake);
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return ahead[1];
    }
};