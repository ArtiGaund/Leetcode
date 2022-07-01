class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto e:edges)
        {
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                if(dist[i][k]!=INT_MAX)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(i!=j and dist[k][j]!=INT_MAX)
                            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int res=0;
        int m=n;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
                if(dist[i][j]<=d and dist[i][j]!=INT_MAX)
                    count++;
            if(count<=m)
            {
                m=count;
                res=i;
            }
        }
        return res;
    }
};