class UnionFind
{
    public: 
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(int n):parent(n),rank(n),count(0)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    void setParent(int x)
    {
        parent[x]=x;
        count++;
    }
    int find(int x)
    {
        if(x==-1) return x;
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        if(m==0)
            return {};
        UnionFind uf(m*n);
        vector<vector<int>> v(m,vector<int>(n,0));
        int k=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                v[i][j]=k++;
        vector<bool> vis(m*n,false);
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto pos:positions)
        {
            int r=pos[0];
            int c=pos[1];
           int index=v[r][c];
            if(!vis[index])
            {
                uf.setParent(index);
                vis[index]=true;
            }
            for(auto it:dir)
            {
                int x=r+it[0];
                int y=c+it[1];
                if(x>=0 and x<m and y>=0 and y<n)
                {
                    int index1=v[x][y];
                    if(vis[index1]==true)
                        uf.unionset(index,index1);
                }
            }
            res.push_back(uf.getCount());
        }
        return res;
    }
};