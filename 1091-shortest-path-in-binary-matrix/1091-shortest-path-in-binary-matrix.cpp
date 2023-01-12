class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        if(grid[0][0]==1 or grid[row-1][col-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int res=0;
        vector<pair<int,int>> dir={{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1},{1,0},{0,1},{1,1}};
        while(!q.empty())
        {
            res++;
            int size=q.size();
            while(size--)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r==row-1 and c==col-1) return res;
                for(auto d:dir)
                {
                    int new_r=r+d.first;
                    int new_c=c+d.second;
                    if(new_r>=0 and new_r<row and new_c>=0 and new_c<col and 
                       grid[new_r][new_c]==0)
                    {
                        q.push({new_r,new_c});
                        grid[new_r][new_c]=1;
                    }
                }
            }
        }
        return -1;
    }
};