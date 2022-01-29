class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int dest) {
        unordered_map<int,vector<int>> mp;
        for(auto e:edges)
        {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(s);
        vis[s]=true;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(cur==dest) return true;
            for(auto e:mp[cur])
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