class Solution {
public:
    vector<int> colors;
    bool isPossible(vector<int> graph[],int n,int cur,int col)
    {
        for(auto it:graph[cur])
        {
            if(colors[it]==col) return false;
        }
        return true;
    }
    bool dfs(vector<int> graph[],int cur,int n)
    {
        if(cur==n+1) return true;
        for(int col=1;col<=4;col++)
        {
            if(isPossible(graph,n,cur,col))
            {
                colors[cur]=col;
                if(dfs(graph,cur+1,n)) return true;
                colors[cur]=0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //convert it into graph
        vector<int> graph[n+1];
        for(int i=0;i<paths.size();i++)
        {
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }
        colors=vector<int>(n+1,0);
        for(int i=0;i<=n;i++)
        {
            if(colors[i]==0) dfs(graph,i,n);
        }
        colors.erase(colors.begin());
        return colors;
    }
};