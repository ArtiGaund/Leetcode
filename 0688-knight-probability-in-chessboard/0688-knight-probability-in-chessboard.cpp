class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
        vector<pair<int,int>> dir={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        vector<vector<double>> prevDp(n,vector<double>(n,0));
        vector curDp(n,vector<double>(n,0));
        prevDp[row][col]=1;
        for(int moves=1;moves<=k;moves++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    curDp[i][j]=0;
                    for(auto d:dir)
                    {
                        int prevI=i-d.first,prevJ=j-d.second;
                        if(prevI>=0 and prevI<n and prevJ>=0 and prevJ<n)
                            curDp[i][j]+=prevDp[prevI][prevJ]/8;
                    }
                }
            }
            prevDp.swap(curDp);
        }
        double total=0;
        for(auto r:prevDp)
            for(auto c:r)
                total+=c;
        return total;
    }
};