class Solution {
public:
    vector<int> dfs(int node,int parent,vector<int> adj[],string &labels,vector<int> &res)
        {
        vector<int> nodeCounts(26);
        nodeCounts[labels[node]-'a']=1;
        for(auto child:adj[node])
        {
            if(child==parent) continue;
            vector<int> childCount=dfs(child,node,adj,labels,res);
            for(int i=0;i<26;i++)
                nodeCounts[i]+=childCount[i];
        }
        res[node]=nodeCounts[labels[node]-'a'];
        return nodeCounts;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> res(n,0);
        dfs(0,-1,adj,labels,res);
        return res;
    }
};