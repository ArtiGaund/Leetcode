class Solution {
public:
    //BFS
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(auto p:pre)
        {
            adj[p[0]].push_back(p[1]);
            vis[p[0]][p[1]]=true;
        }
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i]) in[it]++;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0) q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                for(int i=0;i<n;i++)
                    if(vis[i][node]) vis[i][it]=true;
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        vector<bool> res;
        for(auto q:queries)
            res.push_back(vis[q[0]][q[1]]);
        return res;
    }
};