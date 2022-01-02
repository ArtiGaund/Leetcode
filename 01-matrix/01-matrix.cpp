class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int dis=0;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0) q.push({i,j}); //  keep track of all 0's
                else mat[i][j]=INT_MAX; //else initialize mat to max
            }
        }
        vector<vector<int>> direction={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty())
        {
            vector<int> cur=q.front();
            q.pop();
            for(auto d:direction)
            {
                int i=cur[0]+d[0];
                int j=cur[1]+d[1];
                if(i<0 or i>=n or j<0 or j>=m or mat[i][j]<=mat[cur[0]][cur[1]]+1) continue;
                q.push({i,j});
                mat[i][j]=mat[cur[0]][cur[1]]+1;
            }
        }
        return mat;
    }
};