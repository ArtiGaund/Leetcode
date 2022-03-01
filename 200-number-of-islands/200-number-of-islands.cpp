class UnionFind
{
    public:vector<int> parent;
    vector<int> rank;
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
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0) return 0;
        UnionFind uf(grid);
        int num_of_island=0;
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]='0';
                    for(auto it:dir)
                    {
                        int x=i+it[0];
                        int y=j+it[1];
                        if(x>=0 and x<m and y>=0 and y<n and grid[x][y]=='1')
                            uf.unionset(i*n+j,x*n+y);
                    }
                }
            }
        }
        return uf.getCount();
    }
};