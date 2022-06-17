class Solution {
public:
    #define tu tuple<int,int,int>
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        priority_queue<tu,vector<tu>,greater<tu>> pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!pq.empty())
        {
            int t=get<0>(pq.top());
            int x=get<1>(pq.top());
            int y=get<2>(pq.top());
            pq.pop();
            if(x==m-1 and y==n-1) return t;
            for(auto d:dir)
            {
                int new_x=x+d.first;
                int new_y=y+d.second;
                
                if(new_x>=0 and new_x<m and new_y>=0 and new_y<n and vis[new_x][new_y]==0)
                {
                    vis[new_x][new_y]=1;
                    pq.push({max(t,grid[new_x][new_y]),new_x,new_y});
                }
            }
        }
        return -1;
    }
};