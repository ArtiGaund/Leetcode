class Solution {
public:
    void bfs(int node,vector<int> graph[],vector<int> &vis)
    {
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for(auto it:graph[cur])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),m=isConnected[0].size();
        vector<int> graph[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i,graph,vis);
            }
        }
        return count;
    }
};