class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>> &res,int color,int old)
    {
        res[row][col]=color;
        m=image.size();
        n=image[0].size();
        for(auto d:dir)
        {
            int r=row+d.first;
            int c=col+d.second;
            if(r>=0 and r<m and c>=0 and c<n and image[r][c]==old and res[r][c]!=color)
                dfs(r,c,image,res,color,old);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        vector<vector<int>> res=image;
        dfs(sr,sc,image,res,color,old);
        return res;
    }
};