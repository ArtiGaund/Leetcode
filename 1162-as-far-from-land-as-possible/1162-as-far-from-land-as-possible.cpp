class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        int maxlen=0;
        
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int x=cur.first;
            int y=cur.second;
            vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
            for(auto d:dir)
            {
                int new_x=x+d.first;
                int new_y=y+d.second;
                if(new_x>=0 and new_x<m and new_y>=0 and new_y<n and grid[new_x][new_y]==0)
                {
                    q.push({new_x,new_y});
                    grid[new_x][new_y]=grid[x][y]+1;
                    maxlen=max(maxlen,grid[new_x][new_y]);
                }
            }
        }
        return (maxlen>0?maxlen-1:-1);
    }
};