class Solution {
public:
    int findMinDistance(vector<vector<int>> &adjList,int n){
        vector<int> dp(n);
        dp[n-1]=0;
        for(int cur=n-2;cur>=0;cur--){
            int minDist=n;
            for(auto neighbor:adjList[cur]){
                minDist=min(minDist,dp[neighbor]+1);
            }
            dp[cur]=minDist;
        }
        return dp[0];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> adjList(n,vector<int>(0));
        for(int i=0;i<n-1;i++)
            adjList[i].push_back(i+1);
        for(auto road:queries){
            int u=road[0],v=road[1];
            adjList[u].push_back(v);
            res.push_back(findMinDistance(adjList,n));
        }
        return res;
    }
};