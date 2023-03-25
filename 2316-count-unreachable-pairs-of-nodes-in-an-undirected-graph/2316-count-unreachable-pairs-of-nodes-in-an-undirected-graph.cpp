class UnionSet
{
    public:
    vector<int> rank,parent;
    UnionSet(int n)
    {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findParent(int u)
    {
        if(u==parent[u]) return u;
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionSet dsu(n);
        for(auto e:edges)
            dsu.unionset(e[0],e[1]);
        unordered_map<int,int> componentSize;
        for(int i=0;i<n;i++) componentSize[dsu.findParent(i)]++;
        long long noOfPaths=0,remNodes=n;
        for(auto c:componentSize)
        {
            int size=c.second;
            noOfPaths+=size*(remNodes-size);
            remNodes-=size;
        }
        return noOfPaths;
    }
};