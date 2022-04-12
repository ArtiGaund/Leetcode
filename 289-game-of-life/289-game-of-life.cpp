class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0||board[0].size()==0)
            return;
        int m=board.size();
        int n=board[0].size();
        int x[]={-1,-1,0,1,1,1,0,-1};
        int y[]={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    int nx=i+x[k];
                    int ny=j+y[k];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&(board[nx][ny]&1)==1)
                    {
                        count++;
                    }
                }
                if(count<2) //<2 die
                    board[i][j]&=1;
                if(count==2||count==3) //same state
                    board[i][j] |=board[i][j]<<1;
                if(count==3) //go alive
                    board[i][j]|=2;
                if(count>3) //>3 die
                    board[i][j]&=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=board[i][j]>>1;
            }
        }
    }
};