class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &board,int m,int n)
    {
        if(i<0 or i>=m or j<0 or j>=n or board[i][j]!='O') return;
        board[i][j]='#';
        dfs(i-1,j,board,m,n);
        dfs(i+1,j,board,m,n);
        dfs(i,j-1,board,m,n);
        dfs(i,j+1,board,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') dfs(i,0,board,m,n);
            if(board[i][n-1]=='O') dfs(i,n-1,board,m,n);
        }
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O') dfs(0,j,board,m,n);
            if(board[m-1][j]=='O') dfs(m-1,j,board,m,n);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='#') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};