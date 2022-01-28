class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // BFS using queue
        if(mat.size()==0) return mat;
        int row=mat.size();
        int col=mat[0].size();
        queue<pair<int,int>> q; //to store the boundaries
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==0) //store boundaries of cell which contain 0
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
                int l=p.first;
                int r=p.second;
                if(l>=0 and l<row and r>=0 and r<col and !vis[l][r] and mat[l][r]==1)
                {
                    vis[l][r]=true;
                    mat[l][r]=step;
                     q.push({l-1,r});
                     q.push({l+1,r});
                     q.push({l,r-1});
                     q.push({l,r+1});
                }
            }
        }
        return mat;
    }
};