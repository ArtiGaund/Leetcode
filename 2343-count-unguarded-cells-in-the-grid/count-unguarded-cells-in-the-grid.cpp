class Solution {
public:
const int UNGUARDED = 0;
const int GUARDED = 1;
const int GUARD = 2;
const int WALL = 3;
void traverse(int row,int col,vector<vector<int>> &grid){
    for(int r=row-1;r>=0;r--){
        if(grid[r][col]==WALL || grid[r][col]==GUARD) break;
        grid[r][col]=GUARDED;
    }
    for(int r=row+1;r<grid.size();r++){
        if(grid[r][col]==GUARD || grid[r][col]==WALL) break;
        grid[r][col]=GUARDED;
    }
    for(int c=col-1;c>=0;c--){
        if(grid[row][c]==GUARD ||grid[row][c]== WALL)break;
        grid[row][c]=GUARDED;
    }
    for(int c=col+1;c<grid[row].size();c++){
        if(grid[row][c]==WALL || grid[row][c]==GUARD) break;
        grid[row][c]=GUARDED;
    }
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,UNGUARDED));
        // mark guards position
        for(const auto &guard:guards){
            grid[guard[0]][guard[1]]=GUARD;
        }
        // mark walls position
        for(const auto &wall:walls){
            grid[wall[0]][wall[1]]=WALL;
        }
        // mark cells as guarded by traversing from each guard
        for(const auto &guard:guards){
            traverse(guard[0],guard[1],grid);
        }
        // count unguarded cells
        int count=0;
        for(const auto &row:grid){
            for(const auto &cell:row){
                if(cell==UNGUARDED) count++;
            }
        }
        return count;
    }
};