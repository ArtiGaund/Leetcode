class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> b(n,string(n,'.'));
        backtrack(b,0,n,res);
        return res;
    }
    void backtrack(vector<string> &b,int col,int n,vector<vector<string>> &res)
    {
        if(col==n)
        {
            res.push_back(b);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isValid(b,row,col,n))
            {
                b[row][col]='Q';
                backtrack(b,col+1,n,res);
                b[row][col]='.';
            }
        }
    }
    bool isValid(vector<string> b,int row,int col,int n)
    {
        // horizontal check
        for(int x = 1; x <= col; x++){
            if(b[row][col-x] == 'Q') return false;
        }
        // diagonals cheack
        for(int x = 1; row-x >= 0 && col-x >= 0; x++){
            if(b[row-x][col-x] == 'Q') return false;
        }
        for(int x=1;row+x<n and col-x>=0;x++)
            if(b[row+x][col-x]=='Q') return false;
        return true;
    }
};