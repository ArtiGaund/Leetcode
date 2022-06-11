class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 and n==1) return 0;
        int di[]={-1,0,1,0};
        int dj[]={0,-1,0,1};
        queue<tuple<int,int,int>> q;
        q.push({0,0,k});
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(k+1,0)));
        vis[0][0][k]=1;
        int ans=0;
        while(!q.empty())
        {
            ans++;
            for(int size=q.size();size>0;size--)
            {
                const auto [x,y,eliminate]=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int adjx=x+di[i];
                    int adjy=y+dj[i];
                    if(adjx<0 or adjx>=m or adjy<0 or adjy>=n) continue;
                    if(adjx==m-1 and adjy==n-1) return  ans;
                    if(grid[adjx][adjy]==1 and eliminate==0) continue;
                    const int newEliminate=eliminate-grid[adjx][adjy];
                    if(vis[adjx][adjy][newEliminate]) continue;
                    q.push({adjx,adjy,newEliminate});
                    vis[adjx][adjy][newEliminate]=1;
                }
            }
        }
        return -1;
    }
};