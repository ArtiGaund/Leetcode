class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int peri=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    peri+=4; //increment perimeter by 4
                    //already visited connected up and left element
                    if(i>0 and grid[i-1][j]==1) 
                        peri-=2;
                    if(j>0 and grid[i][j-1]==1) peri-=2;
                }
            }
        }
        return peri;
    }
};