class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> oneRow(m,0);
        vector<int> oneCol(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                oneRow[i]+=grid[i][j];
                oneCol[j]+=grid[i][j];
            }
        }
        vector diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                diff[i][j]=2*oneRow[i]+2*oneCol[j]-n-m;
        }
        return diff;
    }
};