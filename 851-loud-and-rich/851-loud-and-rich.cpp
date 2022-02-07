class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> adj[n];
        for(auto e:richer)
            adj[e[0]].push_back(e[1]);
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i])
                in[it]++;
        vector<int> res(n);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            res[i]=i;
            if(in[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(quiet[res[it]]>quiet[res[node]])
                    res[it]=res[node];
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        return res;
    }
};