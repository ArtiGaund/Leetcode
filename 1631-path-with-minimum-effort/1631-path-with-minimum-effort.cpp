class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 and col==m-1) return diff;
            for(auto d:dir)
            {
                int r=row+d.first;
                int c=col+d.second;
                if(r>=0 and r<n and c>=0 and c<m)
                {
                    int newEffort=max(abs(heights[row][col]-heights[r][c]),diff);
                    if(newEffort<dist[r][c]){
                        dist[r][c]=newEffort;
                        pq.push({newEffort,{r,c}});
                    }
                }
            }
        }
        return 0;
    }
};