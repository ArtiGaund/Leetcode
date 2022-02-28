class Solution {
public:
    //topological sort
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        stack<int> s;
        s.push(source);
        vector<bool> seen(n,false);
        while(!s.empty())
        {
            int cur=s.top();
            s.pop();
            if(cur==destination) return true;
            if(seen[cur]) continue;
            seen[cur]=true;
            for(auto it:adj[cur])
                s.push(it);
        }
        return false;
    }
};