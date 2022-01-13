class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n+1);
        vector<int> degree(n+1,0);
        for(auto &e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int sec=0;
        queue<pair<int,double>> q;
        q.push({1,1.0});
        vector<bool> vis(n+1,false);
        vis[1]=true;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                if(cur.first==target) 
                    return (sec==t or sec<t and degree[cur.first]==0?cur.second:0);
                for(int neighbor:graph[cur.first])
                {
                    if(!vis[neighbor])
                    {
                        vis[neighbor]=true;
                        q.push({neighbor,cur.second/degree[cur.first]});
                        degree[neighbor]--;
                    }
                }
            }
            sec++;
        }
        return 0;
    }
};