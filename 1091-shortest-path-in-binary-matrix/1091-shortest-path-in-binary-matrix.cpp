class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 or grid[m-1][n-1]==1) return -1;
        vector<pair<int,int>> dir={{-1,-1},{-1,0},{0,-1},{1,1},{1,0},{0,1},{1,-1},{-1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                int x=cur.first,y=cur.second;
                if(x==m-1 and y==n-1) return ans;
                for(auto d:dir)
                {
                    int nx=x+d.first;
                    int ny=y+d.second;
                    if(nx>=0 and nx<m and ny>=0 and ny<n and grid[nx][ny]==0)
                    {
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
};