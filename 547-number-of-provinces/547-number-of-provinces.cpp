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
            if(parent[x]!=x) parent[x]=find(parent[x]);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        if(n==0) return 0;
        UnionFind uf(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(isConnected[i][j]==1)
                    uf.unionset(i,j);
        return uf.getCount();
    }
};