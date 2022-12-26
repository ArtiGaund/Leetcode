class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        vector<pair<int,int>> dir={{-1,-1},{-1,0},{0,-1},{1,1},{1,0},{0,1},{-1,1},{1,-1}};
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row==n-1 and col==m-1) return ans;
                for(auto d:dir)
                {
                    int r=row+d.first;
                    int c=col+d.second;
                    if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==0)
                    {
                        q.push({r,c});
                        grid[r][c]=1;
                    }
                }
            }
        }
        return -1;
    }
};