class DisjointSet
{
    public:
    vector<int> rank,parent;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findParent(int u)
    {
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionset(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])
            parent[ulp_v]=ulp_u;
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto e:connections)
        {
            int u=e[0];
            int v=e[1];
            if(ds.findParent(u)==ds.findParent(v)) extra++;
            else ds.unionset(u,v);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(ds.parent[i]==i) cnt++;
        if(extra>=cnt-1) return cnt-1;
        return -1;
    }
};