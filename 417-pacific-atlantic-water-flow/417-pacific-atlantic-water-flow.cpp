class Solution {
public:
    void bfs(vector<vector<int>> &heights,queue<pair<int,int>> q,int m,int n,vector<vector<int>> &vis)
    {
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            int x=cur.first;
            int y=cur.second;
            for(auto d:dir)
            {
                int new_x=x+d.first,new_y=y+d.second;
                if(new_x<0 or new_x>=m or new_y<0 or new_y>=n or vis[new_x][new_y]==1) continue;
                if(heights[new_x][new_y]>=heights[x][y])
                {
                    vis[new_x][new_y]=1;
                    q.push({new_x,new_y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        if(m==0 or n==0) return {};
        vector<vector<int>> vis1(m,vector<int>(n,0));
        vector<vector<int>> vis2(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            vis1[i][0]=1;
            q.push({i,0});
        }
        for(int j=0;j<n;j++)
        {
            vis1[0][j]=1;
            q.push({0,j});
        }
        bfs(heights,q,m,n,vis1);
        while(!q.empty()) q.pop();
        for(int i=0;i<m;i++)
        {
            vis2[i][n-1]=1;
            q.push({i,n-1});
        }
        for(int j=0;j<n;j++)
        {
            vis2[m-1][j]=1;
            q.push({m-1,j});
        }
        bfs(heights,q,m,n,vis2);
        vector<vector<int>> res;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis1[i][j]==vis2[i][j] and vis1[i][j]==1)
                    res.push_back({i,j});
            }
        }
        return res;
    }
};