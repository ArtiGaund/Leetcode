class UnionFind
{
    public:
    vector<int> parent,rank;
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
        if(x!=parent[x])
            x=find(parent[x]);
        return x;
    }
    void unionset(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x!=y)
        {
            if(rank[x]>rank[y]) parent[y]=x;
            else if(rank[x]<rank[y]) parent[x]=y;
            else
            {
                parent[y]=x;
                rank[x]++;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        if(size<n-1) return -1;
        UnionFind uf(n);
        for(auto c:connections)
        {
            uf.unionset(c[0],c[1]);
        }
        return uf.getCount()-1;
    }
};