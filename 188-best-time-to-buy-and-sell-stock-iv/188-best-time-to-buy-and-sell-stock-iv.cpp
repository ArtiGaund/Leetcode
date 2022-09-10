class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(2*k+1,0),cur(2*k+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int trans=2*k-1;trans>=0;trans--)
            {
                if(trans%2==0)
                {
                    int take=-prices[index]+prev[trans+1];
                    int nottake=0+prev[trans];
                    cur[trans]=max(take,nottake);
                }
                else
                {
                    int take=prices[index]+prev[trans+1];
                    int nottake=0+prev[trans];
                    cur[trans]=max(take,nottake);
                }
            }
            prev=cur;
        }
        return prev[0];
    }
};