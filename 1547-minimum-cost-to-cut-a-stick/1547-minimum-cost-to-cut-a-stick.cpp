class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int size=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(size+2,vector<int>(size+2,0));
        for(int i=size;i>=1;i--)
        {
            for(int j=1;j<=size;j++)
            {
                if(i>j) continue;
                int mini=INT_MAX;
                for(int index=i;index<=j;index++)
                {
                    int cost=(cuts[j+1]-cuts[i-1])+dp[i][index-1]+dp[index+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][size];
    }
};