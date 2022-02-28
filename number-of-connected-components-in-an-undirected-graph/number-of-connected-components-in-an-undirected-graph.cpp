class UnionFind
{
    public:
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(int n):parent(n),rank(n),count(n)
    {
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
    void unionSet(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x!=y)
        {
            if(rank[x]>rank[y])
                parent[y]=x;
            else
            {
                parent[x]=y;
                if(rank[x]==rank[y]) rank[y]++;
            }
            count--;
        }
    }
    int getCount()
    {
        return count;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // if(edges.size()!=n-1) return 0;
        UnionFind uf(n);
        for(auto v:edges)
        {
            uf.unionSet(v[0],v[1]);
        }
        return uf.getCount();
    }
};