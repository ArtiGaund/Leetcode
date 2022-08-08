class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int row,int col,vector<vector<int>> &res,vector<vector<int>> &image,int old,int color)
    {
        res[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(auto d:dir)
        {
            int r=row+d.first;
            int c=col+d.second;
            if(r>=0 and r<n and c>=0 and c<m and image[r][c]==old and res[r][c]!=color)
            {
                dfs(r,c,res,image,old,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        vector<vector<int>> res=image;
        dfs(sr,sc,res,image,old,color);
        return res;
    }
};