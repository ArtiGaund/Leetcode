class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        unordered_map<int,vector<int>> graph; //create graph
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(source);
        vis[source]=true;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(cur==des) return true;
            for(auto e:graph[cur])
            {
                if(!vis[e])
                {
                    vis[e]=true;
                    q.push(e);
                }
            }
        }
        return false;
    }
};