class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //BFS
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i]) in[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0)
                q.push(i);
        vector<int> res;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node])
            {
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};