class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
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
                    auto cur=q.front();
                    q.pop();
                    for(auto it:graph[cur])
                    {
                        if(color[it]==-1)
                        {
                            q.push(it);
                            color[it]=1-color[cur];
                        }
                        else if(color[it]==color[cur]) return false;
                    }
                }
            }
        }
        return true;
    }
};