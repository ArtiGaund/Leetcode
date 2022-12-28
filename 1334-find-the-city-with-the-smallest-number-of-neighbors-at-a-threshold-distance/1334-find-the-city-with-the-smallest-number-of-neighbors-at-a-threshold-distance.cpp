class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int Threshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto e:edges)
        {
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++)
            dist[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                if(dist[i][k]!=INT_MAX)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(dist[k][j]!=INT_MAX and i!=j)
                            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int cntCity=n;
        int cityno=-1;
        for(int city=0;city<n;city++)
        {
            int cnt=0;
            for(int neigh=0;neigh<n;neigh++)
            {
                if(dist[city][neigh]<=Threshold and dist[city][neigh]!=INT_MAX)
                    cnt++;
            }
            if(cnt<=cntCity)
            {
                cntCity=cnt;
                cityno=city;
            }
        }
        return cityno;
    }
};