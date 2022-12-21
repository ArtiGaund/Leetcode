class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto cur=q.front();
                q.pop();
                for(auto d:dir)
                {
                    int r=cur.first+d.first;
                    int c=cur.second+d.second;
                    if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1)
                    {
                        q.push({r,c});
                        grid[r][c]=2;
                        fresh--;
                    }
                }
            }
            if(!q.empty()) time++;
        }
        return (fresh==0?time:-1);
    }
};