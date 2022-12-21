class Solution {
public:
    void bfs(vector<vector<char>> &grid,int row,int col,vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for(auto d:dir)
            {
                int r=cur.first+d.first;
                int c=cur.second+d.second;
                if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[r][c]=='1')
                {
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    count++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};