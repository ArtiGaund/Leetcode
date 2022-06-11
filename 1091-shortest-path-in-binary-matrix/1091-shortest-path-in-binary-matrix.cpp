class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(grid[0][0]==1 or grid[row-1][col-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<pair<int,int>> dir={{-1,-1},{-1,1},{1,-1},{1,1},{1,0},{0,1},{-1,0},{0,-1}};
        int ans=0;
        grid[0][0]=1;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                int x=cur.first;
                int y=cur.second;
                if(x==row-1 and y==col-1) return ans;
                for(auto d:dir)
                {
                    int adjx=x+d.first;
                    int adjy=y+d.second;
                    if(adjx>=0 and adjx<row and adjy>=0 and adjy<col and grid[adjx][adjy]==0)
                    {
                        grid[adjx][adjy]=1;
                        q.push({adjx,adjy});
                    }
                }
            }
        }
        return -1;
    }
};