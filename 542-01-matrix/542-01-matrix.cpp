class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
         {   
            for(int j=0;j<n;j++)
             {  
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=INT_MAX;
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            for(auto d:dir)
            {
                int x=cur.first+d.first;
                int y=cur.second+d.second;
                if(x<0 or x>=m or y<0 or y>=n or mat[x][y]<=mat[cur.first][cur.second]+1) continue;
                q.push({x,y});
                mat[x][y]=mat[cur.first][cur.second]+1;
            }
        }
        return mat;
    }
};