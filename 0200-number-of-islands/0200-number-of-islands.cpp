class Solution {
public:
    void bfs(vector<vector<char>> &grid,int row,int col,vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<pair<int,int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
        int n=grid.size(),m=grid[0].size();
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for(auto d:dir)
            {
                int x=cur.first+d.first;
                int y=cur.second+d.second;
                if(x>=0 and x<n and y>=0 and y<m and !vis[x][y] and grid[x][y]=='1')
                {
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int island=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    island++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return island;
    }
};