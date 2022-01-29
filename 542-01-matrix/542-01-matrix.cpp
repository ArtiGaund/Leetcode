class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        int step=0;
        while(!q.empty())
        {
            step++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x>=0 and x<row and y>=0 and y<col and !vis[x][y] and mat[x][y]==1)
                {
                    vis[x][y]=true;
                    mat[x][y]=step;
                    q.push({x-1,y});
                    q.push({x+1,y});
                    q.push({x,y-1});
                    q.push({x,y+1});
                }
            }
        }
        return mat;
    }
};