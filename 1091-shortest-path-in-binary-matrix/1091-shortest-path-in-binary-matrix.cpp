class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1 or grid[m-1][n-1]==1) return -1;
        vector<pair<int,int>> dir={{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1},{1,0},{0,1},{1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        int steps=0;
        grid[0][0]=1;
        while(!q.empty())
        {
            int size=q.size();
            steps++;
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                int x=cur.first;
                int y=cur.second;
                if(x==m-1 and y==n-1) return steps;
                for(auto d:dir)
                {
                    int new_x=x+d.first;
                    int new_y=y+d.second;
                    
                    if(new_x>=0 and new_x<m and new_y>=0 and new_y<n and grid[new_x][new_y]==0)
                    {
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=1;
                    }
                }
            }
        }
        return -1;
    }
};