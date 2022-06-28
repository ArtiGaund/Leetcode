#define tu tuple<int,int,int>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        priority_queue<tu,vector<tu>,greater<tu>> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!pq.empty())
        {
            auto [dis,i,j]=pq.top();
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j]=1;
            for(auto d:dir)
            {
                int x=i+d.first,y=j+d.second;
                if(x>=0 and x<m and y>=0 and y<n and !vis[x][y])
                {
                    int diff=abs(heights[i][j]-heights[x][y]);
                    if(dist[x][y]>diff)
                    {
                        dist[x][y]=max(dist[i][j],diff);
                        pq.push({dist[x][y],x,y});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};