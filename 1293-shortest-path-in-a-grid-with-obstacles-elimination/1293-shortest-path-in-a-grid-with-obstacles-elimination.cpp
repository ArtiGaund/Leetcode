class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        if(m==1 and n==1) return 0;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,pair<int,int>>> q;
        vector<vector<vector<bool>>> seen(m,vector<vector<bool>>(n,vector<bool>(k+1,0)));
        seen[0][0][k]=1;
        int res=0;
        q.push({0,{0,k}});
        while(!q.empty())
        {
            res++;
            int size=q.size();
            while(size--)
            {
                auto x=q.front().first;
                auto y=q.front().second.first;
                auto eliminate=q.front().second.second;
                q.pop();
                // if(x==m-1 and y==n-1) return res;
                for(auto d:dir)
                {
                    int new_x=x+d.first;
                    int new_y=y+d.second;
                    if(new_x<0 or new_x>=m or new_y<0 or new_y>=n) continue;
                    if(new_x==m-1 and new_y==n-1) return res;
                    if(grid[new_x][new_y]==1 and eliminate==0) continue;
                    const int newEliminate=eliminate-grid[new_x][new_y];
                    if(seen[new_x][new_y][newEliminate]) continue;
                    q.push({new_x,{new_y,newEliminate}});
                    seen[new_x][new_y][newEliminate]=1;
                }
            }
        }
        return -1;
    }
};