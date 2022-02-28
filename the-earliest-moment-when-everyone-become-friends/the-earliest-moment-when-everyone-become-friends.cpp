class UnionFind
{
    public: vector<int> parent;
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
    bool unionSet(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x==y) return false;
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
        return true;
    }
    int getCount()
    {
        return count;
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        int getCount=n;
        UnionFind uf(n);
        for(auto v:logs)
        {
            if(uf.unionSet(v[1],v[2]))
                getCount--;
            if(getCount==1) return v[0];
        }
        return -1;
    }
};