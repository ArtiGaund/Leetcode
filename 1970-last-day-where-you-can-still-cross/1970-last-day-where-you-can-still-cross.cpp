class Solution {
public:
    bool canCross(int row,int col,vector<vector<int>> &cells,int day)
    {
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>> grid(row,vector<int>(col));
        queue<pair<int,int>> q;
        for(int i=0;i<day;i++)
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        for(int i=0;i<col;i++)
        {
            if(grid[0][i]==0)
            {
                q.push({0,i});
                grid[0][i]=-1;
            }
        }
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int r=cur.first,c=cur.second;
            if(r==row-1) return true;
            for(auto d:dir)
            {
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr>=0 and nr<row and nc>=0 and nc<col and grid[nr][nc]==0)
                {
                    q.push({nr,nc});
                    grid[nr][nc]=-1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=1;
        int right=row*col;
        while(left<right)
        {
            int mid=right-(right-left)/2;
            if(canCross(row,col,cells,mid)) left=mid;
            else right=mid-1;
        }
        return left;
    }
};