class Solution {
public:
    vector<int> colors;
    bool isPossible(vector<int> graph[],int n,int cur,int color)
    {
        for(auto it:graph[cur])
        {
            if(colors[it]==color) return false;
        }
        return true;
    }
    bool dfs(vector<int> graph[],int n,int cur)
    {
        if(cur==n+1) return true;
        for(int color=1;color<=4;color++)
        {
            if(isPossible(graph,n,cur,color))
            {
                colors[cur]=color;
                if(dfs(graph,n,cur+1)) return true;
                colors[cur]=0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> graph[n+1];
        for(auto p:paths)
        {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        colors=vector<int>(n+1,0);
        for(int i=0;i<=n;i++)
        {
            if(colors[i]==0) dfs(graph,n,i);
        }
        colors.erase(colors.begin());
        return colors;
    }
};