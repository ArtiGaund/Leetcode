class Solution {
public:
    int mod=(int)(1e9+7);
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    grid[i][j]=-1;
            }
        }
       vector<int> prev(c,0);
        for(int i=0;i<r;i++)
        {
            vector<int> temp(c,0);
            for(int j=0;j<c;j++)
            {
                temp[j]=0;
                if(grid[i][j]==-1) temp[j]=0;
                else if(i==0 and j==0) temp[j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[c-1];
    }
};