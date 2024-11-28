class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> minObstacles(m,vector<int>(n,INT_MAX));
        minObstacles[0][0]=0;
        deque<array<int,3>> dq;
        dq.push_back({0,0,0});
        while(!dq.empty()){
            auto cur=dq.front();
            dq.pop_front();
            int obstacles=cur[0],row=cur[1],col=cur[2];
            for(auto d:dir){
                int newR=row+d.first,newC=col+d.second;
                if(isValid(grid,newR,newC) and minObstacles[newR][newC]==INT_MAX){
                    if(grid[newR][newC]==1){
                        minObstacles[newR][newC]=obstacles+1;
                        dq.push_back({obstacles+1,newR,newC});
                    }else{
                        minObstacles[newR][newC]=obstacles;
                        dq.push_front({obstacles,newR,newC});
                    }
                }
            }
        }
        return minObstacles[m-1][n-1];
    }
    bool isValid(vector<vector<int>> &grid,int row,int col){
        return (row>=0 and col>=0 and row<grid.size() and col<grid[0].size());
    }
};