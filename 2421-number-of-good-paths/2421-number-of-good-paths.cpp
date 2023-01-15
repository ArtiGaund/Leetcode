class UnionFind
{
    public:
    vector<int> rank,parent;
    UnionFind(int n):parent(n),rank(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int findParent(int x)
    {
        if(parent[x]!=x)
            parent[x]=findParent(parent[x]);
        return parent[x];
    }
    void unionset(int a,int b)
    {
        int x=findParent(a);
        int y=findParent(b);
        if(x!=y)
        {
            if(rank[x]>rank[y]) parent[y]=x;
            else if(rank[x]<rank[y]) parent[x]=y;
            else
            {
                parent[y]=x;
                rank[x]++;
            }
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int> adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        map<int,vector<int>> valToNodes;
        for(int node=0;node<n;node++)
            valToNodes[vals[node]].push_back(node);
        UnionFind uf(n);
        int goodPaths=0;
        for(auto [val,nodes]:valToNodes)
        {
            for(int node:nodes)
            {
                for(int neighbor:adj[node])
                {
                    if(vals[node]>=vals[neighbor])
                        uf.unionset(node,neighbor);
                }
            }
            unordered_map<int,int> group;
            for(int u:nodes) group[uf.findParent(u)]++;
            for(auto [node,size]:group)
                goodPaths+=(size*(size+1)/2);
        }
        return goodPaths;
    }
};