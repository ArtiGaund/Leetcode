class Solution {
public:
    int findMinIndex(vector<int> &arr){
        int minIndex=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[minIndex]) minIndex=i;
        }
        return minIndex;
    }
    int buyChoco(vector<int>& prices, int money) {
        int minIndex=findMinIndex(prices);
        int minCost=prices[minIndex];
        prices[minIndex]=INT_MAX;
        int secMinIndex=findMinIndex(prices);
        minCost+=prices[secMinIndex];
        if(minCost<=money) return money-minCost;
        return money;
    }
};