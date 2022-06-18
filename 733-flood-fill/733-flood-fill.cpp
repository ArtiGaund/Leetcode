class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int color,int newColor)
    {
        if(i<0 or i>=image.size() or j<0 or j>=image[0].size() or image[i][j]!=color) return;
        image[i][j]=newColor;
        dfs(image,i-1,j,color,newColor);
        dfs(image,i+1,j,color,newColor);
        dfs(image,i,j-1,color,newColor);
        dfs(image,i,j+1,color,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color=image[sr][sc];
        if(color!=newColor) dfs(image,sr,sc,color,newColor);
        return image;
    }
};