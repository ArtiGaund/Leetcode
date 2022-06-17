class Solution {
public:
    void dfs(vector<vector<char>> &board,int i,int j,int m,int n)
    {
        if(i<0 or i>=m or j<0 or j>=n or board[i][j]!='X') return;
        board[i][j]='.';
        dfs(board,i-1,j,m,n);
        dfs(board,i+1,j,m,n);
        dfs(board,i,j-1,m,n);
        dfs(board,i,j+1,m,n);
    }
    int countBattleships(vector<vector<char>>& board) {
        int battleship=0;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X')
                {
                    battleship++;
                    dfs(board,i,j,m,n);
                }
            }
        }
        return battleship;
    }
};