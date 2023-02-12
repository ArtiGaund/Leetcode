class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<(m+1)/2;c++)
            {
                int temp=image[r][c]^1;
                image[r][c]=image[r][m-1-c]^1;
                image[r][m-1-c]=temp;
            }
        }
        return image;
    }
};