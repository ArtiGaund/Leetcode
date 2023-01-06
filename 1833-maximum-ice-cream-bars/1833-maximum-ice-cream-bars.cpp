class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int m=*max_element(costs.begin(),costs.end());
        int icecreams=0;
        vector<int> costFreq(m+1,0);
        for(auto cost:costs)
            costFreq[cost]++;
        for(int cost=1;cost<=m;cost++)
        {
            if(costFreq[cost]==0) continue;
            if(coins<cost) break;
            int count=min(costFreq[cost],coins/cost);
            coins-=cost*count;
            icecreams+=count;
        }
        return icecreams;
    }
};