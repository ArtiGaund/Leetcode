class UnionFind
{
    public:
    vector<int> parent,rank;
    UnionFind(int n):parent(n),rank(n)
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
    bool unionset(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x==y) return false;
        if(rank[x]>rank[y]) parent[y]=x;
        else if(rank[x]<rank[y]) parent[x]=y;
        else
        {
            parent[y]=x;
            rank[x]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UnionFind uf(n+1);
        for(auto e:edges)
        {
            if(!uf.unionset(e[0],e[1])) return {e[0],e[1]};
        }
        return {};
    }
};