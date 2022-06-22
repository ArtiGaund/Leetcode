class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int old,int color,int m,int n)
    {
        if(i<0 or i>=m or j<0 or j>=n or image[i][j]!=old) return;
        image[i][j]=color;
        dfs(image,i-1,j,old,color,m,n);
        dfs(image,i+1,j,old,color,m,n);
        dfs(image,i,j-1,old,color,m,n);
        dfs(image,i,j+1,old,color,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        int oldColor=image[sr][sc];
        if(m==0 or n==0) return image;
        if(oldColor==color) return image;
        dfs(image,sr,sc,oldColor,color,m,n);
        return image;
    }
};