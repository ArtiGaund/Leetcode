class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int island=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    island++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return island;
    }
    void bfs(int row,int col,vector<vector<char>> grid,vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        int m=grid.size(),n=grid[0].size();
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for(auto d:dir)
            {
                int r=d.first+cur.first;
                int c=d.second+cur.second;
                if(r>=0 and r<m and c>=0 and c<n and !vis[r][c] and grid[r][c]=='1')
                {
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }
};