class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int row=grid.size();
        int col=grid[0].size();
        if(grid[0][0]==1 or grid[row-1][col-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        // vector<vector<bool>> vis(row,vector<bool>(col,false));
        // vis[0][0]=true;
        grid[0][0]=1;
        vector<pair<int,int>> dir={{-1,-1},{0,-1},{-1,0},{1,1},{1,0},{0,1},{1,-1},{-1,1}};
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                q.pop();
                int l=p.first;
                int r=p.second;
                if(l==row-1 and r==col-1) return ans;
                for(auto d:dir)
                {
                    int x=l+d.first;
                    int y=r+d.second;
                    if(x>=0 and x<row and y>=0 and y<col and grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        // vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};