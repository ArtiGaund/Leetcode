class Solution {
public:
    //BFS
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row==0) return 0;
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    grid[i][j]='0'; //mark as visited
                    queue<int> q; //to check neighbors
                    q.push(i*col+j);
                    while(!q.empty())
                    {
                        int index=q.front();
                        q.pop();
                        int r=index/col;
                        int c=index%col;
                        if(r-1>=0 and grid[r-1][c]=='1')
                        {
                            q.push((r-1)*col+c);
                            grid[r-1][c]='0';
                        }
                        if(r+1<row and grid[r+1][c]=='1')
                        {
                            q.push((r+1)*col+c);
                            grid[r+1][c]='0';
                        }
                        if(c-1>=0 and grid[r][c-1]=='1')
                        {
                            q.push(r*col+(c-1));
                            grid[r][c-1]='0';
                        }
                        if(c+1<col and grid[r][c+1]=='1')
                        {
                            q.push(r*col+(c+1));
                            grid[r][c+1]='0';
                        }
                    }
                }
            }
        }
        return count;
    }
    
};