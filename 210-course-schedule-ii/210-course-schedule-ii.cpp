class Solution {
public:
    // dfs
    bool isCycle(int node,vector<int> adj[],vector<bool> &todo,vector<bool> &done,stack<int> &s)
    {
        if(todo[node]) return false;
        if(done[node]) return true;
        todo[node]=done[node]=true;
        for(auto it:adj[node])
            if(!isCycle(it,adj,todo,done,s)) return false;
        s.push(node);
        todo[node]=false;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<bool> todo(n,0),done(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(!todo[i] and !isCycle(i,adj,todo,done,s)) return {};
        }
        vector<int> res;
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};