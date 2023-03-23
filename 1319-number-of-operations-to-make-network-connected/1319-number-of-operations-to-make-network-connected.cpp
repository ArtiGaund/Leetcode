class UnionSet
{
    public:
    vector<int> parent,rank;
    UnionSet(int n)
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionSet us(n);
        int extra=0;
        for(auto c:connections)
        {
            int a=c[0];
            int b=c[1];
            if(us.findParent(a)==us.findParent(b)) extra++;
            else us.unionset(a,b);
        }
        int count=0;
        for(int i=0;i<n;i++)
            if(us.parent[i]==i) count++;
        if(extra>=count-1) return count-1;
        return -1;
    }
};