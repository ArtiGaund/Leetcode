class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int first=cost[0];
        if(n==0) return 0;
        if(n==1) return first;
        int second=cost[1];
        if(n<=2) return min(first,second);
        for(int i=2;i<n;i++)
        {
            int temp=cost[i]+min(first,second);
            first=second;
            second=temp;
        }
        return min(first,second);
    }
};