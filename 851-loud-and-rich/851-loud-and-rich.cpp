class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> adj[n];
        for(auto e:richer)
            adj[e[0]].push_back(e[1]);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i]) indegree[it]++;
        vector<int> res(n,INT_MAX);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            res[i]=i;
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(res[it]==INT_MAX or quiet[res[it]]>quiet[res[node]])
                    res[it]=res[node];
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return res;
    }
};