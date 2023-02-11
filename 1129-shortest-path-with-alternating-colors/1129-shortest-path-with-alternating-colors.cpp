class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<pair<int,int>> adj[n];
        for(auto r:red)
            adj[r[0]].push_back({r[1],0});
        for(auto b:blue)
            adj[b[0]].push_back({b[1],1});
        vector<int> res(n,-1);
        vector<vector<bool>> vis(n,vector<bool>(2));
        queue<vector<int>> q;
        q.push({0,0,-1});
        vis[0][1]=vis[0][0]=true;
        res[0]=0;
        while(!q.empty())
        {
            auto ele=q.front();
            int node=ele[0],steps=ele[1],prevColor=ele[2];
            q.pop();
            for(auto &[neigh,color]:adj[node])
            {
                if(!vis[neigh][color] and color!=prevColor)
                {
                    vis[neigh][color]=true;
                    q.push({neigh,1+steps,color});
                    if(res[neigh]==-1) res[neigh]=1+steps;
                }
            }
        }
        return res;
    }
};