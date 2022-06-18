class Solution {
public:
    #define tu tuple<int,int,int>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        priority_queue<tu,vector<tu>,greater<tu>> pq;
        pq.push({0,0,0});
        dis[0][0]=0;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!pq.empty())
        {
            int curDis=get<0>(pq.top());
            int x=get<1>(pq.top());
            int y=get<2>(pq.top());
            pq.pop();
            if(vis[x][y]) continue;
            vis[x][y]=1;
            int diff=0;
            for(auto d:dir)
            {
                int new_x=x+d.first;
                int new_y=y+d.second;
                if(new_x>=0 and new_x<m and new_y>=0 and new_y<n and !vis[new_x][new_y])
                {
                    diff=abs(heights[x][y]-heights[new_x][new_y]);
                    if(dis[new_x][new_y]>diff)
                    {
                        dis[new_x][new_y]=max(diff,dis[x][y]);
                        pq.push({dis[new_x][new_y],new_x,new_y});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};