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
    bool unionset(int a,int b)
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
            return true;
        }
        return false;
    }
    int getCount()
    {
        return count;
    }
};
class Solution {
public:
    int max_val=1000;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       UnionFind uf(max_val+1);
        for(auto e:edges)
        {
            if(!uf.unionset(e[0],e[1])) return e;
        }
        return {};
    }
    
};