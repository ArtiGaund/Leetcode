class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(int nei:adj[cur]){
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        vector<vector<int>> ancestors(n);
        vector<set<int>> st(n);
        for(int node:topo){
            for(int nei:adj[node]){
                st[nei].insert(node);
                st[nei].insert(st[node].begin(),st[node].end());
            }
        }
        for(int i=0;i<ancestors.size();i++){
            ancestors[i].assign(st[i].begin(),st[i].end());
            sort(ancestors[i].begin(),ancestors[i].end());
        }
        return ancestors;
    }
};