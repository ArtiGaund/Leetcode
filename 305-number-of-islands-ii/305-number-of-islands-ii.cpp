class Solution {
public:
    void dsfInfectIslandId(int newId, int r, int c, vector<vector<int>> &grid) {
        if ((r > -1) && (c > -1) && (r < grid.size()) && (c < grid[0].size()) && (grid[r][c] != 0) && grid[r][c] != newId) {
            grid[r][c] = newId;
            dsfInfectIslandId(newId, r-1, c, grid);
            dsfInfectIslandId(newId, r+1, c, grid);
            dsfInfectIslandId(newId, r, c-1, grid);
            dsfInfectIslandId(newId, r, c+1, grid);
        }
        return;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        int numOfIslands = 0;
        vector<int> result;
        int currentIslandId = 0;
        int retrievedIslandId = 0;
        int numOfBridged = 0;

        for (auto position : positions) {
            if (grid[position[0]][position[1]] != 0) {
                result.push_back(numOfIslands);
                continue;
            }
            if (position[0] - 1 > -1 && grid[position[0] - 1][position[1]] != 0) {
                ++numOfBridged;
                retrievedIslandId = grid[position[0] - 1][position[1]];
            }
            if (position[0] + 1 < grid.size() && grid[position[0] + 1][position[1]] != 0) {
                if (retrievedIslandId != grid[position[0] + 1][position[1]]) {
                    ++numOfBridged;
                    if (retrievedIslandId == 0) {
                        retrievedIslandId = grid[position[0] + 1][position[1]];
                    }
                    else {
                        dsfInfectIslandId(retrievedIslandId, position[0] + 1, position[1], grid);
                    }
                }
            }
            if (position[1] - 1 > -1 && grid[position[0]][position[1] - 1] != 0) {
                if (retrievedIslandId != grid[position[0]][position[1] - 1]) {
                    ++numOfBridged;
                    if (retrievedIslandId == 0) {
                        retrievedIslandId = grid[position[0]][position[1] - 1];
                    }
                    else {
                        dsfInfectIslandId(retrievedIslandId, position[0], position[1] - 1, grid);
                    }
                }                
            }
            if (position[1] + 1 < grid[0].size() && grid[position[0]][position[1] + 1] != 0) {
                if (retrievedIslandId != grid[position[0]][position[1] + 1]) {
                    ++numOfBridged;
                    if (retrievedIslandId == 0) {
                        retrievedIslandId = grid[position[0]][position[1] + 1];
                    }
                    else {
                        dsfInfectIslandId(retrievedIslandId, position[0], position[1] + 1, grid);
                    }
                }
            }
            if (retrievedIslandId != 0) {
                grid[position[0]][position[1]] = retrievedIslandId;
                retrievedIslandId = 0;
                numOfIslands -= (numOfBridged - 1);
                numOfBridged = 0;
            }
            else {
                ++currentIslandId;
                ++numOfIslands;
                grid[position[0]][position[1]] = currentIslandId;
            }
            result.push_back(numOfIslands);
        }
        return result;
    }
};