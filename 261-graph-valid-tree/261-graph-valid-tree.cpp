class UnionFind
{
    public:
        vector<int> parent;
        vector<int> rank;
        int count;
    UnionFind(int n)
    {
        parent=vector<int>(n);
        rank=vector<int>(n);
        count=n;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int x)
    {
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unionFind(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x==y) return false;
        if(rank[x]>rank[y])
            parent[y]=x;
        else
        {
            parent[x]=y;
            if(rank[x]==rank[y]) rank[y]++;
        }
        count--;
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        UnionFind uf(n);
        for(auto v:edges)
        {
            if(!uf.unionFind(v[0],v[1]))
                return false;
        }
        return true;
    }
};