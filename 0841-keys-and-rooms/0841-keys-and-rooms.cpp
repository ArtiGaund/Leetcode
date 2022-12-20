class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> graph[n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
                graph[i].push_back(rooms[i][j]);
        }
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            if(!graph[cur].size()) continue;
            for(auto it:graph[cur])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(!vis[i]) return false;
        return true;
    }
};