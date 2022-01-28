class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        int time=0;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                q.pop();
                int l=p.first;
                int r=p.second;
                for(auto d:dir)
                {
                    int x=l+d.first;
                    int y=r+d.second;
                    if(x>=0 and x<row and y>=0 and y<col and grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            if(!q.empty()) time++;
        }
        return fresh==0?time:-1;
    }
};