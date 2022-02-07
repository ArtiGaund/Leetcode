class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto e:pre)
            adj[e[1]].push_back(e[0]);
        stack<int> s;
        vector<bool> todo(n,0),done(n,0);
        for(int i=0;i<n;i++)
        {
            if(!done[i] and !acyclic(i,todo,done,adj,s))
                return {};
        }
        vector<int> res;
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
    bool acyclic(int node,vector<bool> &todo,vector<bool> &done,vector<int> adj[],stack<int> &s)
    {
        if(todo[node]) return false;
        if(done[node]) return true;
        todo[node]=done[node]=true;
        for(auto it:adj[node])
        {
            if(!acyclic(it,todo,done,adj,s)) return false;
        }
        s.push(node);
        todo[node]=false;
        return true;
    }
};