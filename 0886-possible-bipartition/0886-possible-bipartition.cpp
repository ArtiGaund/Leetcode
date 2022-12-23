class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        for(auto d:dislikes)
        {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        vector<int> color(n+1,-1);
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto it:graph[node])
                    {
                        if(color[it]==-1)
                        {
                            color[it]=1-color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};