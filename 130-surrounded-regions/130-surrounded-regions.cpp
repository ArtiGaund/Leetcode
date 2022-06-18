class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j,int m,int n)
    {
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]!='O') return;
        grid[i][j]='#';
        dfs(grid,i-1,j,m,n);
        dfs(grid,i+1,j,m,n);
        dfs(grid,i,j-1,m,n);
        dfs(grid,i,j+1,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        if(m==0 or n==0) return;
        //finding 'O' in first and last col
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') dfs(board,i,0,m,n);
            if(board[i][n-1]=='O') dfs(board,i,n-1,m,n);
        }
        //finding 'O' in first and last row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O') dfs(board,0,j,m,n);
            if(board[m-1][j]=='O') dfs(board,m-1,j,m,n);
        }
        //changing 'O' to 'X' and '#' to 'O'
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};