class Solution {
public:
    // DFS
    int m,n;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i<0 or j<0 or i>=m or j>=n or board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        if(m==0) return;
        n=board[0].size();
        // first and last col finding 'o' on boundaries
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][n-1]=='O')
                dfs(board,i,n-1);
        }
        // first and last row finding 'o' on boundaries
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[m-1][j]=='O')
                dfs(board,m-1,j);
        }
        //changing 'O' to 'X' and '#' to 'O'
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};