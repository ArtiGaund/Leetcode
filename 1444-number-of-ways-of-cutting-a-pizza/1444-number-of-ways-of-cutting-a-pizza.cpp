class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int row=pizza.size(),col=pizza[0].size();
        vector apples(row+1,vector<int>(col+1));
        vector f(row,vector<int>(col));
        for(int r=row-1;r>=0;r--)
        {
            for(int c=col-1;c>=0;c--)
            {
                apples[r][c]=(pizza[r][c]=='A')+apples[r+1][c]+apples[r][c+1]-apples[r+1][c+1];
                f[r][c]=apples[r][c]>0;
            }
        }
        const int mod=1000000007;
        for(int remain=1;remain<k;remain++)
        {
            vector g(row,vector<int>(col));
            for(int r=0;r<row;r++)
            {
                for(int c=0;c<col;c++)
                {
                    for(int n_r=r+1;n_r<row;n_r++)
                    {
                        if(apples[r][c]-apples[n_r][c]>0)
                            g[r][c]=(g[r][c]+f[n_r][c])%mod;
                    }
                    for(int n_c=c+1;n_c<col;n_c++)
                    {
                        if(apples[r][c]-apples[r][n_c]>0)
                            g[r][c]=(g[r][c]+f[r][n_c])%mod;
                    }
                }
                
            }
            f=g;
        }
        return f[0][0];
    }
};