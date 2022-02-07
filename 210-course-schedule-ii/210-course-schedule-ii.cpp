class Solution {
public:
    //BFS
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        // if(pre.size()==0) return {0};
        for(auto it:pre)
            adj[it[1]].push_back(it[0]);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        vector<int> res(n);
        int i=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res[i++]=node;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(i==n) return res;
        return {};
    }
};