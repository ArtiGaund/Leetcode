class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    int cur=q.front();
                    q.pop();
                    for(int it:graph[cur])
                    {
                        if(color[it]==-1)
                        {
                            color[it]=1-color[cur];
                            q.push(it);
                        }
                        else if(color[it]==color[cur]) return false;
                    }
                }
            }
        }
        return true;
    }
};