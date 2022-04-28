class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int m,n;
    bool isValid(int x,int y)
    {
        if(x>=0 and x<m and y>=0 and y<n) return true;
        return false;
    }
    bool bfs(vector<vector<int>> path,int k)
    {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(101,vector<bool>(101,false));
        q.push({0,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p.first==m-1 and p.second==n-1) return true;
            for(int i=0;i<4;i++)
            {
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if(isValid(x,y) and !visited[x][y])
                {
                    if(abs(path[x][y]-path[p.first][p.second])<=k)
                    {
                        visited[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        int low=0,high=10e6;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(bfs(heights,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};