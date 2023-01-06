class Solution {
public:
    // pair<int,pair<int,int>>
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!pq.empty())
        {
            auto cur=pq.top();
            pq.pop();
            int t=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;
            if(x==n-1 and y==n-1) return t;
            for(auto d:dir)
            {
                int new_x=x+d.first;
                int new_y=y+d.second;
                if(new_x>=0 and new_x<n and new_y>=0 and new_y<n and vis[new_x][new_y]==0)
                {
                    vis[new_x][new_y]=1;
                    pq.push({max(grid[new_x][new_y],t),{new_x,new_y}});
                }
            }
        }
        return -1;
    }
};