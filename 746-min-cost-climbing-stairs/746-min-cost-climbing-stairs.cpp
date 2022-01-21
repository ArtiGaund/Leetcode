class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int first=cost[0];
        int sec=cost[1];
        if(n<=2) return min(first,sec);
        for(int i=2;i<n;i++)
        {
            int cur=cost[i]+min(first,sec);
            first=sec;
            sec=cur;
        }
        return min(first,sec);
    }
};