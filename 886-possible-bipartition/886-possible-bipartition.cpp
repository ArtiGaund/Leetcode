class Solution {
public:
    bool dfs(int node,vector<int> &color,vector<int> graph[])
    {
        if(color[node]==-1) color[node]=1;
        for(int it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!dfs(it,color,graph)) return false;
            }
            else if(color[it]==color[node]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,color,graph)) return false;
            }
        }
        return true;
    }
};