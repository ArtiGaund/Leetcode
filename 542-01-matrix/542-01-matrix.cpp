class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        if(m==0 or n==0) return mat;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    for(auto d:dir)
                    {
                        int x=i+d.first;
                        int y=j+d.second;
                        q.push({x,y});
                    }
                }
            }
        }
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int step=0;
        while(!q.empty())
        {
            step++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto cur=q.front();
                q.pop();
                int x=cur.first;
                int y=cur.second;
                if(x>=0 and x<m and y>=0 and y<n and !vis[x][y] and mat[x][y]==1)
                {
                    vis[x][y]=1;
                    mat[x][y]=step;
                    for(auto d:dir)
                    {
                        int new_x=x+d.first,new_y=y+d.second;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        return mat;
    }
};