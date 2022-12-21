class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    int m,n;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        m=image.size();
        n=image[0].size();
        vector<vector<int>> res=image;
        dfs(image,res,sr,sc,color,old);
        return res;
    }
    void dfs(vector<vector<int>> &image,vector<vector<int>> &res,int r,int c,int color,int old)
    {
        res[r][c]=color;
        for(auto d:dir)
        {
            int row=r+d.first;
            int col=c+d.second;
            if(row>=0 and row<m and col>=0 and col<n and image[row][col]==old and res[row][col]!=color)
                dfs(image,res,row,col,color,old);
        }
    }
};