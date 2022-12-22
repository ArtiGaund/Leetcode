class Solution {
public:
    int n,m;
    void dfs(int row,int col,vector<vector<char>> &board,vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(auto d:dir)
        {
            int r=row+d.first;
            int c=col+d.second;
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and board[r][c]=='O')
                dfs(r,c,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] and board[i][0]=='O')
                dfs(i,0,board,vis);
            if(!vis[i][m-1] and board[i][m-1]=='O')
                dfs(i,m-1,board,vis);
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] and board[0][j]=='O')
                dfs(0,j,board,vis);
            if(!vis[n-1][j] and board[n-1][j]=='O')
                dfs(n-1,j,board,vis);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] and board[i][j]=='O')
                    board[i][j]='X';
    }
};