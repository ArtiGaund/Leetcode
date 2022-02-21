class Solution {
public:
    // DFS
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        int row=image.size();
        int col=image[0].size();
        int old=image[sr][sc];
        image[sr][sc]=newColor;
        vector<int> dir={0,-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int nr=sr+dir[i];
            int nc=sc+dir[i+1];
            if(nr<0 or nr>=row or nc<0 or nc>=col or image[nr][nc]!=old) continue;
            floodFill(image,nr,nc,newColor);
        }
        return image;
    }
};