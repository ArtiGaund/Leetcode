class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        if(m==1 and n==1) return 0;
        int di[]={-1,0,1,0};
        int dj[]={0,-1,0,1};
        queue<tuple<int,int,int>> q;
        q.push({0,0,k});
        vector<vector<vector<bool>>> seen(m,vector<vector<bool>>(n,vector<bool>(k+1,0)));
        seen[0][0][k]=1;
        int ans=0;
        while (!q.empty()) {
          ++ans;
          for (int sz = q.size(); sz > 0; --sz) {
            const auto [i, j, eliminate] = q.front();
            q.pop();
            for (int l = 0; l < 4; ++l) {
              const int x = i + di[l];
              const int y = j + dj[l];
              if (x < 0 || x == m || y < 0 || y == n)
                continue;
              if (x == m - 1 && y == n - 1)
                return ans;
              if (grid[x][y] == 1 && eliminate == 0)
                continue;
              const int newEliminate = eliminate - grid[x][y];
              if (seen[x][y][newEliminate])
                continue;
              q.push({x, y, newEliminate});
              seen[x][y][newEliminate] = true;
            }
          }
        }
        return -1;
    }
};