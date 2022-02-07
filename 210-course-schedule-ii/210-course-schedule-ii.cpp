class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto e:pre)
            adj[e[1]].push_back(e[0]);
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i])
                in[it]++;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0) q.push(i);
        vector<int> res(n);
        int i=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res[i++]=node;
            for(auto it:adj[node])
            {
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        if(i==n) return res;
        return {};
    }
};