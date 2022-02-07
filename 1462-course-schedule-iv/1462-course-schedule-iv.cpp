class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(auto it:pre)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i]) in[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0) q.push(i);
        unordered_map<int,unordered_set<int>> mp;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                in[it]--;
                if(in[it]==0) q.push(it);
                mp[it].insert(node);
                for(auto prev:mp[node])
                    mp[it].insert(prev);
            }
        }
        vector<bool> res;
        for(auto pair:queries)
        {
            int child=pair[1],par=pair[0];
            res.push_back(mp[child].count(par));
        }
        return res;
    }
};