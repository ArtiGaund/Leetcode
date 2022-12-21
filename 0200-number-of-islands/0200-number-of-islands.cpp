class UnionFind
{
    public:
    vector<int> parent,rank;
    int count;
    UnionFind(vector<vector<char>> &grid)
    {
        count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    parent.push_back(i*n+j);
                    count++;
                }
                else parent.push_back(-1);
                rank.push_back(0);
            }
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
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0) return 0;
        UnionFind uf(grid);
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]=='0';
                    for(auto d:dir)
                    {
                        int r=i+d.first;
                        int c=j+d.second;
                        if(r>=0 and r<m and c>=0 and c<n and grid[r][c]=='1')
                            uf.unionset(i*n+j,r*n+c);
                    }
                }
            }
        }
        return uf.getCount();
    }
};