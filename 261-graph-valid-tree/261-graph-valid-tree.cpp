class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<int> adj[n+1];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        set<int> seen;
        q.push(0);
        seen.insert(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int neighbor:adj[node])
            {
                if(seen.find(neighbor)!=seen.end()) continue;
                seen.insert(neighbor);
                q.push(neighbor);
            }
        }
        return seen.size()==n;
    }
};