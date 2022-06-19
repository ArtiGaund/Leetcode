#define tu tuple<int,int,int>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int m=height.size(),n=height[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        priority_queue<tu,vector<tu>,greater<tu>> pq;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0 or i==m-1 or j==n-1)
                {
                    pq.push({height[i][j],i,j});
                    vis[i][j]=1;
                }
            }
        }
        int water=0;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!pq.empty())
        {
            int h=get<0>(pq.top());
            int x=get<1>(pq.top());
            int y=get<2>(pq.top());
            pq.pop();
            for(auto d:dir)
            {
                int new_x=x+d.first;
                int new_y=y+d.second;
                if(new_x>=0 and new_x<m and new_y>=0 and new_y<n and !vis[new_x][new_y])
                {
                    water+=max(0,h-height[new_x][new_y]);
                    if(height[new_x][new_y]>=h) 
                        pq.push({height[new_x][new_y],new_x,new_y});
                    else pq.push({h,new_x,new_y});
                    vis[new_x][new_y]=1;
                }
            }
        }
        return water;
    }
};