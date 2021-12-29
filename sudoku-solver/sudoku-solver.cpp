class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    bool backtrack(vector<vector<char>> &b)
    {
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                if(b[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(isValid(b,i,j,ch))
                        {
                            b[i][j]=ch;
                            if(backtrack(b)) return true;
                            else b[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> b,int r,int c,char ch)
    {
        for(int i=0;i<b.size();i++)
        {
            if(b[i][c]==ch) return false;
            if(b[r][i]==ch) return false;
            if(b[3*(r/3)+i/3][3*(c/3)+i%3]==ch) return false;
        }
        return true;
    }
};