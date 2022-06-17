class Solution {
public:
    
    int countBattleships(vector<vector<char>>& board) {
        int battleship=0;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;
                if(i>0 and board[i-1][j]=='X') continue;
                if(j>0 and board[i][j-1]=='X') continue;
                battleship++;
            }
        }
        return battleship;
    }
};