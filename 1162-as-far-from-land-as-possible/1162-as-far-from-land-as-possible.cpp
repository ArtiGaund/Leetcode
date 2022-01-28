class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>> q,q1;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        int step=0;
        while(!q.empty())
        {
            step++;
            while(!q.empty())
            {
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i>=0 and i<row and j>=0 and j<col and grid[i][j]==0)
                {
                    grid[i][j]=step;
                    q1.push({i-1,j});
                    q1.push({i+1,j});
                    q1.push({i,j-1});
                    q1.push({i,j+1});
                }
            }
            swap(q,q1);
        }
        return step==1?-1:step-1;
    }
};