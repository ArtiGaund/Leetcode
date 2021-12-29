class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        backtrack(res,board,n,0);
        return res;
    }
    void backtrack(vector<vector<string>> &res,vector<string> &board,int n,int col)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isValid(board,row,col))
            {
                board[row][col]='Q';
                backtrack(res,board,n,col+1);
                board[row][col]='.';
            }
        }
    }
    bool isValid(vector<string> &board,int row,int col)
    {
        int n=board.size();
        for(int x=1;x<=col;x++)  //cheack horizontal
            if(board[row][col-x]=='Q') return false;
        for(int x=1;row-x>=0 and col-x>=0;x++)     //check diagonal
            if(board[row-x][col-x]=='Q') return false;
        for(int x=1;row+x<n and col-x>=0;x++)
            if(board[row+x][col-x]=='Q') return false;
        return true;
    }
};