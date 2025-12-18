class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> profitSum(n+1);
        vector<long long> priceSum(n+1);
        for(int i=0;i<n;i++){
            profitSum[i+1]=profitSum[i]+prices[i]*strategy[i];
            priceSum[i+1]=priceSum[i]+prices[i];
        }
        long long res=profitSum[n];
        for(int i=k-1;i<n;i++){
            long long leftSum=profitSum[i-k+1];
            long long rightSum=profitSum[n]-profitSum[i+1];
            long long changeSum=priceSum[i+1]-priceSum[i-k/2+1];
            res=max(res,leftSum+changeSum+rightSum);
        }
        return res;
    }
};