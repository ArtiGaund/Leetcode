class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++) 
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i])
                in[it]++;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0) q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            n--;
            for(auto it:adj[node])
            {
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        return n==0;
    }
};