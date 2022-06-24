class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,vector<int> &vis,int node)
    {
        if(vis[node]) return;
        vis[node]=1;
        for(int j=0;j<isConnected[node].size();j++)
        {
            if(!vis[j] and isConnected[node][j]==1)
                dfs(isConnected,vis,j);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(isConnected,vis,i);
            }
        }
        return count;
    }
};