class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
         int m=grid.size();
        int n=grid[0].size();
        if(m==1 and n==1) return 0;
        queue<tuple<int,int,int>> q;
        q.push({0,0,k});
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(k+1,0)));
        vis[0][0][k]=1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        int steps=0;
        while(!q.empty())
        {
            steps++;
            for(int i=q.size();i>0;i--)
            {
                auto [x,y,eliminate]=q.front();
                q.pop();
                for(auto d:dir)
                {
                    int new_x=x+d.first;
                    int new_y=y+d.second;
                    if(new_x==m-1 and new_y==n-1) return steps;
                    if(new_x<0 or new_x>=m or new_y<0 or new_y>=n) continue;
                    if(grid[new_x][new_y]==1 and eliminate==0) continue;
                    int new_eliminate=eliminate-grid[new_x][new_y];
                    if(vis[new_x][new_y][new_eliminate]) continue;
                    q.push({new_x,new_y,new_eliminate});
                    vis[new_x][new_y][new_eliminate]=1;
                }
            }
        }
        return -1;
    }
};