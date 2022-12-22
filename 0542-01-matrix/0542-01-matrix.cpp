class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int row=cur.first.first;
            int col=cur.first.second;
            int steps=cur.second;
            dist[row][col]=steps;
            for(auto d:dir)
            {
                int r=row+d.first;
                int c=col+d.second;
                if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and mat[r][c]==1)
                {
                    q.push({{r,c},steps+1});
                    vis[r][c]=1;
                }
            }
        }
        return dist;
    }
};