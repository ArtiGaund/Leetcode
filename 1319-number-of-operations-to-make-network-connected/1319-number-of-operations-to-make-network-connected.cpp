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
        }
        count--;
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
        if(size<n-1) return -1; //not enough edges
        UnionFind uf(n);
        for(auto c:connections)
        {
            int x=c[0];
            int y=c[1];
            if(uf.find(x)!=uf.find(y)) uf.unionset(x,y);
        }
        return uf.getCount()-1;
       
    }
};