class UnionFind
{
    public:
    vector<int> rank,parent;
    UnionFind(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findParent(int u)
    {
        if(parent[u]==u) return u;
        else return parent[u]=findParent(parent[u]);
    }
    void unionset(int u,int v)
    {
        int x=findParent(u);
        int y=findParent(v);
        if(rank[x]<rank[y]) parent[x]=y;
        else if(rank[x]>rank[y]) parent[y]=x;
        else
        {
            parent[x]=y;
            rank[y]++;
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind uf(n+1);
        for(auto r:roads)
            uf.unionset(r[0],r[1]);
        int res=INT_MAX;
        for(auto r:roads)
            if(uf.findParent(1)==uf.findParent(r[0]))
                res=min(res,r[2]);
        return res;
    }
};