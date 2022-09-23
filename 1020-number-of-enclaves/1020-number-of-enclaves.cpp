class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] and grid[i][0]==1) 
            {
                q.push({i,0});
                vis[i][0]=1;
            }
            if(!vis[i][m-1] and grid[i][m-1]==1) 
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] and grid[0][j]==1)
            { 
                q.push({0,j});
                vis[0][j]=1;
            }
            if(!vis[n-1][j] and grid[n-1][j]==1)
            {
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto d:dir)
            {
                int r=row+d.first,c=col+d.second;
                if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[r][c]==1)
                {
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==1) count++;
            }
        }
        return count;
    }
};